"use strict;"
document.addEventListener('DOMContentLoaded',()=>{
    let table = document.querySelector("table")
    table.addEventListener("click",change_couleur)    

    document.querySelectorAll("h1, h2, h3, h4, h5, h6, p, span, td, button, a").forEach(element => {
        if (element.textContent.trim() !== "") {
            element.setAttribute("data-text_orig", element.textContent);
        }
    })

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

const cherche_dans_paragraphes_de_main_v2  = (that) => {
    let searchBarValue = that.value

    let p = document.querySelector("main").querySelectorAll("p")
    let find=false
    p.forEach(element => {
        
        let originalText = element.dataset.text_orig
        if(originalText.includes(searchBarValue)){
             element.innerHTML = originalText.replace(searchBarValue,"<span class='find'>"+searchBarValue+"</span>")
             find=true
        }else{
             element.innerText = element.dataset.text_orig
        }
    });
    if(find){
        that.setCustomValidity("")
    }else{
        that.setCustomValidity("Invalid")
    }
}

const move_img = (e) => {
    console.log(e)
    if(e.buttons === 1){
        currentElement = e.target
        currentElement.style.left+=e.movementX
        currentElement.style.top+=e.movementY


    }
}