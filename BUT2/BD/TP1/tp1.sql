SET SERVEROUTPUT ON;


CREATE PUBLIC SYNONYM FILM FOR ens2004.FILM;
CREATE PUBLIC SYNONYM INDIVIDU FOR ens2004.INDIVIDU;
CREATE PUBLIC SYNONYM ACTEUR FOR ens2004.ACTEUR;
CREATE PUBLIC SYNONYM EXEMPLAIRE FOR ens2004.EXEMPLAIRE;
CREATE PUBLIC SYNONYM FILM FOR ens2004.FILM;



CREATE OR REPLACE FUNCTION nbFilms(numInd ens2004.individu.numIndividu%TYPE) RETURN NUMBER AS
cpt NUMBER;
BEGIN 
SELECT COUNT(*) INTO cpt 
FROM ens2004.FILM F
WHERE numInd=F.realisateur;
RETURN cpt;
END nbFilms;
/
EXECUTE DBMS_OUTPUT.PUT_LINE(nbFilms(2872));
/
CREATE OR REPLACE FUNCTION nbFilmsNom(nomRea ens2004.individu.nomIndividu%TYPE) RETURN NUMBER AS
cpt NUMBER;
BEGIN 
SELECT COUNT(*) INTO cpt 
FROM ens2004.FILM F
INNER JOIN ens2004.INDIVIDU I ON F.realisateur=I.numIndividu 
WHERE nomRea=I.nomIndividu;
RETURN cpt;
END nbFilmsNom;
/
EXECUTE DBMS_OUTPUT.PUT_LINE(nbFilmsNom('DIVERS'));
/
SELECT nomIndividu
FROM ens2004.INDIVIDU
WHERE numIndividu=2872;
/
CREATE OR REPLACE PROCEDURE afficheFilms(nomRea ens2004.INDIVIDU.nomIndividu%TYPE) AS

CURSOR monCurseur IS
    SELECT F.numFilm,F.titre
    FROM ens2004.FILM F 
    INNER JOIN ens2004.INDIVIDU I ON F.realisateur=I.numIndividu
    WHERE nomRea=I.nomIndividu;

BEGIN
FOR ligneCurseur IN monCurseur
LOOP
    DBMS_OUTPUT.PUT_LINE(ligneCurseur.numFilm||'   '||ligneCurseur.titre);
END LOOP;
END afficheFilms;

/

EXECUTE afficheFilms('DIVERS');

/

CREATE TABLE LOCATION (numExemplaire NUMBER,
    dateLocation DATE, 
    numClient NUMBER,
    dateEnvoi DATE,
    dateRetour DATE,
    CONSTRAINT fk_numClient FOREIGN KEY (numClient) REFERENCES CLIENTBUT2(numClient),
    CONSTRAINT fk_numExemplaire FOREIGN KEY (numExemplaire) REFERENCES ens2004.EXEMPLAIRE(numExemplaire),
    PRIMARY KEY(numExemplaire,dateLocation)
    ); 
    
    
CREATE TABLE CLIENTBUT2 (
    numClient NUMBER PRIMARY KEY,
    nomClient VARCHAR2(50),
    prenomClient VARCHAR2(50),
    motDePasse VARCHAR2(50),
    adrClient VARCHAR2(50),
    CPClient NUMBER
    ); 
    
    

    
CREATE OR REPLACE FUNCTION nbExemplairesFilms(numFi ens2004.EXEMPLAIRE.numFilm%TYPE) RETURN NUMBER AS 
cpt NUMBER;
BEGIN 

SELECT COUNT(*)INTO cpt
FROM ens2004.EXEMPLAIRE E 
WHERE numFi=E.numFilm;

RETURN cpt;
END nbExemplairesFilms;
/
EXECUTE DBMS_OUTPUT.PUT_LINE(nbExemplairesFilms(2872));
/
SELECT *
FROM ens2004.EXEMPLAIRE;
/

CREATE OR REPLACE TRIGGER dateDepasse 
BEFORE INSERT ON LOCATION
FOR EACH ROW
DECLARE 
CURSOR monCurseur IS
        SELECT L.numClient, L.numExemplaire
        FROM LOCATION L
        WHERE MONTHS_BETWEEN(SYSDATE, L.dateLocation) > 1 AND L.dateRetour is NULL;
BEGIN
FOR ligneCurseur IN monCurseur 
    LOOP 
    IF ligneCurseur.numClient=:NEW.numClient THEN
        DBMS_OUTPUT.PUT_LINE('L utilisateur ' || :NEW.numClient || ' n as toujours pas rendu le livre ' || ligneCurseur.numExemplaire );
    END IF;
    END LOOP;
    END dateDepasse;
/
SELECT *
FROM ens2004.EXEMPLAIRE;
/
INSERT INTO LOCATION VALUES(621,SYSDATE-366,1,SYSDATE-340,NULL);

INSERT INTO CLIENTBUT2 VALUES (1,'GHELLAB','Ibra','1234',NULL,91390);

INSERT INTO LOCATION VALUES(7070,SYSDATE-366,1,SYSDATE-340,NULL);
/
CREATE OR REPLACE TRIGGER dateDepasseNewVersion
BEFORE INSERT ON LOCATION
FOR EACH ROW

DECLARE 

cpt NUMBER;
        
BEGIN
SELECT COUNT(*) INTO cpt
        FROM LOCATION L
        WHERE MONTHS_BETWEEN(SYSDATE, L.dateLocation) > 1 AND L.dateRetour is NULL AND L.numClient=:NEW.numClient;
    
    IF cpt>0 THEN
        RAISE_APPLICATION_ERROR(-20001,'Inscription dans la table non autorisé');
    END IF;
    
    END dateDepasse;
/
CREATE OR REPLACE FUNCTION nbNonRendus(numC CLIENT.numClient%TYPE) RETURN NUMBER AS
cpt NUMBER;
BEGIN
SELECT COUNT(*)INTO cpt
FROM LOCATION L
WHERE L.numClient=numC AND DateRetour is NULL;
RETURN cpt;
END nbNonRendus;
/
CREATE OR REPLACE TRIGGER checkNbNonRendus 
BEFORE INSERT ON LOCATION 
FOR EACH ROW
BEGIN 
IF nbNonRendus(:NEW.numCLient)>3 THEN
RAISE_APPLICATION_ERROR(-20001,'Plus de 3 locations non rendus');
END IF;
END checkNbNonRendus;
/



CREATE OR REPLACE TRIGGER checkDateEnvoi
AFTER INSERT ON LOCATION 
FOR EACH ROW 
BEGIN 
IF SYSDATE-DateLocation >2 AND DateEnvoi IS NULL THEN
DBMS_OUTPUT.PUT_LINE('Il faut envoyer le livre '||numExemplaire||' delai de 48 heures dépassés');
END IF;
END checkDateEnvoi;