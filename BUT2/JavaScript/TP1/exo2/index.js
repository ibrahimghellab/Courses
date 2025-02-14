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
