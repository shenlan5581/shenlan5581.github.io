

//document.getElementById("s").onclick = show();
var stats=0;
function show(x)
{   if(stats == 0){
      document.getElementById(x).style.display = "block";
      stats =1;
    }else{
        document.getElementById(x).style.display = "none";
        stats =0;
    }  
}

 
 