"use strict;"
function rajoute_un_click() {
    let helloButton=document.getElementById("hello-button")
    let text=helloButton.innerText
    if(text=="Hello!"){
        helloButton.innerText="re hello"
        alert("welcome !")
    }else{
        alert("on s'est déja vu non ?")
    }
}

function rajoute_un_click_alt(that){
    let text=that.innerText
    if(text=="Hello!"){
        that.innerText="re hello"
        alert("welcome !")
    }else{
        alert("on s'est déja vu non ?")
    }
}