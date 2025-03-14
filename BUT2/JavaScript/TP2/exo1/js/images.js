"use strict;"
document.addEventListener('DOMContentLoaded',()=>{
    let cadre_01 = document.getElementById("cadre_01")
    let cadre_02 = document.getElementById("cadre_02")
    let cadre_03 = document.getElementById("cadre_03")
    let filtre_01 = document.getElementById("filtre_01")


    cadre_01.addEventListener("mousemove",move_img)
    cadre_02.addEventListener("mousemove",move_img)
    cadre_03.addEventListener("mousemove",move_img)
    filtre_01.addEventListener("mousemove", move_img)



    let images = document.querySelector("div.album").querySelectorAll("img")

    images.forEach(element => {
        element.addEventListener("click",echange_images)
    });

    let cbx = document.getElementById("translate")
    cbx.addEventListener("change",reset_images);
})

const move_img = (e) => {
    if(e.buttons === 1){
        currentElement = e.target

        x = parseInt(currentElement.style.left || 0)
        y = parseInt(currentElement.style.top || 0)
        
        currentElement.style.left=x+e.movementX + "px"
        currentElement.style.top=y+e.movementY + "px"
    }
}

let first = undefined
const echange_images = (e) => {
    if(document.getElementById("translate").checked){
     if(first){
        parent = document.querySelector("div.album")
        afterFirst = first.nextSibling
        
        parent.insertBefore(first,e.target)
        parent.insertBefore(e.target,afterFirst)

        
        
        
        e.target.style.border = "solid 2px black"
        first.style.border = "solid 2px black"
        first = undefined 
        document.getElementById("translate")
     }else{
        first = e.target
        e.target.style.border = "solid 2px cyan"
    
     }
    }
}

const reset_images = (e) => {
    if(first){
        first.style.border = "solid 2px black"
        first = undefined
    }
}
