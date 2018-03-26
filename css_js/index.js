
var stats=0;
 function show(){   
          if(stats == 0){
          document.getElementById('x').style.display = "block";
          stats =1;
        }else{
          document.getElementById('x').style.display = "none";
            stats =0;
        }  
 };
 code =  document.getElementById("s");
 code.onmousemove = show;

 
 
 
