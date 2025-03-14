"use strict;"
document.addEventListener('DOMContentLoaded',()=>{
    let table = document.querySelector("table");
    let tr = table.querySelector("tbody").querySelectorAll("tr");
    let moyennes = new Array(9).fill(0);
    let tfoot = table.querySelector("tfoot");
    let aggreg = tfoot.querySelectorAll("tr")[1].querySelectorAll("td");

    

    for(let i = 0; i< tr.length ; i++){
        let td = tr[i].querySelectorAll("td");
        for(let j = 0; j<td.length; j++){
            moyennes[j] += parseInt(td[j].textContent);
            if(parseInt(td[j].textContent) < 10 ){
                td[j].style.border = "solid 2px red";
            }
        } 
    }

    let nbEleves = tr.length;
    for(let i = 0; i < moyennes.length ; i++){
        moyennes[i]/=nbEleves;
    }
    let td = tfoot.querySelector("tr").querySelectorAll("td");
    for(let i = 0;i<moyennes.length;i++){
        td[i].textContent = moyennes[i].toFixed(2);
    }

    console.log(aggreg);
    
    aggreg[0].textContent = moyennes[0].toFixed(2)
    aggreg[1].textContent = ((moyennes[1] + moyennes[2])/2).toFixed(2)
    aggreg[2].textContent = ((moyennes[3] + moyennes[4])/2).toFixed(2)
    aggreg[3].textContent = ((moyennes[5] + moyennes[6])/2).toFixed(2)
    aggreg[4].textContent = ((moyennes[7] + moyennes[8])/2).toFixed(2)



    let buttons = document.getElementById("buttons");
    console.log(buttons.children[0])
    buttons[1].addEventListener("click",table_to_mobile);
    buttons[1].addEventListener("click",table_to_desktop);

});