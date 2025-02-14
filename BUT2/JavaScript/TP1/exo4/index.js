"use strict;"
document.addEventListener('DOMContentLoaded',()=>{
    let table = document.querySelector("table")
    table.addEventListener("click",change_couleur)    
})

const change_couleur = (e)=>{
    let couleur = e.target.innerText
    let p=document.querySelector("aside").querySelectorAll("p")
    p.forEach(element => {
        element.style.color=couleur   
    });
}

const ajouter_deux_couleurs = ()=>{
    let couleur1 = document.getElementById("first-color").value
    let couleur2 = document.getElementById("second-color").value

    let strClr1 = document.createTextNode(couleur1)
    let strClr2 = document.createTextNode(couleur2)
    
    let table = document.querySelector("table")
    let newTr = document.createElement("tr")
    let newTd1 = document.createElement("td")
    let newTd2 = document.createElement("td")
    newTd1.style.backgroundColor=couleur1
    newTd2.style.backgroundColor=couleur2
    newTd1.appendChild(strClr1)
    newTd2.appendChild(strClr2)

    newTr.appendChild(newTd1)
    newTr.appendChild(newTd2)

    table.appendChild(newTr)

}

const cherche_dans_paragraphes_de_main =(that)=>{
    let searchBarValue = that.value

    let p = document.querySelector("main").querySelectorAll("p")
    let find=false
    p.forEach(element => {
        if(element.innerText.includes(searchBarValue)){
            element.style.backgroundColor="grey"
            find=true
        }else{
            element.style.backgroundColor="transparent"
        }
    });
    if(find){
        that.setCustomValidity("")
    }else{
        that.setCustomValidity("Invalid")
    }

}