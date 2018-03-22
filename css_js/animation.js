
//~~~~~~~~~~~~~~~~~css     箭头动画   ~~~~~~~~~~~~~~~~~~~~~~~~~~~left
var left=document.getElementById("left_arrow_boss");
left.onmousemove=left_change_move;      //鼠标悬停
left.onmouseout=left_change_out;       //鼠标离开
function  left_change_move(){        //此函数 更改最终状态
moveclass("arrow_lefta","arrow_leftb","arrow_leftc","arrow_leftd");       //清除class                         
animationA("arrow_lefta","arrow_lefta","-30deg");        //  第一层更改状态  
animationB("arrow_leftb","arrow_leftb","-30deg","35px");       //  第二层更改状态  
animationA("arrow_leftc","arrow_leftc","30deg"  );       //  第一层更改状态  
animationB("arrow_leftd","arrow_leftd","30deg","35px"  );       //  第二层更改状态  
}
function left_change_out(){    //此函数 更改最终状态
moveclass("arrow_lefta","arrow_leftb","arrow_leftc","arrow_leftd");     //清除class
animationA("arrow_lefta","arrow_leftaa","-50deg");
animationB("arrow_leftb","arrow_leftbb","-50deg","0px");
animationA("arrow_leftc","arrow_leftcc"," 50deg");
animationB("arrow_leftd","arrow_leftdd"," 50deg","0px");
}
/////////////////////////////////////////////////////////////////////////////////////////////
function  animationA(id,class_name,angle ){   //参a  动画ID  参b  动画添加类  //旋转角度   （播放动画 并更改div 结果）
var w= document.getElementById(id);
w.classList.add(class_name);                     //添加动画效果
w.style.transform="rotate("+angle+")"; 
w.style.WebkitTransform="rotate("+angle+")";
}   
function  animationB(id,class_name,angle,width1){   //参a  动画ID  参b  动画添加类  //旋转角度   （播放动画 并更改div 结果）
var   w= document.getElementById(id);
w.classList.add(class_name);                     //添加动画效果
w.style.transform="rotate("+angle+")"; 
w.style.WebkitTransform="rotate("+angle+")"; 
w.style.width=width1;   
}
function moveclass(a,b,c,d){                   //清除状态
var  aa= document.getElementById(a);
aa.className=" ";   
var bb= document.getElementById(b);
bb.className=" ";   
var  cc= document.getElementById(c);
cc.className=" ";   
var dd= document.getElementById(d);
dd.className=" ";   
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~css     箭头动画   ~~~~~~~~~~~~~~~~~~~~~~~~~~~right
var  right=document.getElementById("right_arrow_boss");
 right.onmousemove=change_move;      //鼠标悬停
 right.onmouseout=change_out;       //鼠标离开
function  change_move(){        //此函数 更改最终状态
moveclass("arrow_righta","arrow_rightb","arrow_rightc","arrow_rightd");       //清除class                         
animationA("arrow_righta","arrow_righta","210deg");        //  第一层更改状态  
animationB("arrow_rightb","arrow_rightb","210deg","35px");       //  第二层更改状态  
animationA("arrow_rightc","arrow_rightc","150deg");       //  第一层更改状态  
animationB("arrow_rightd","arrow_rightd","150deg","35px"  );       //  第二层更改状态  
}
function  change_out(){    //此函数 更改最终状态
moveclass("arrow_righta","arrow_rightb","arrow_rightc","arrow_rightd");       //清除class           
animationA("arrow_righta","arrow_rightaa"," 230deg");
animationB("arrow_rightb","arrow_rightbb","130deg","0px");
animationA("arrow_rightc","arrow_rightcc","130deg");
animationB("arrow_rightd","arrow_rightdd"," 50deg","0px");
}


/*************************轮播******图片***************** */ 
window.onload=k;
var intk=0;
function k(){
  intk=1;
}
  var  IMG_SATAE = 1;                //全局常量记录当前显示图片    
  var  go_changeID=0;            
 var HD;                          //handle
$(document).ready(function(){                       //初始操作            
$("#d1").css("background-color","#2c2b2b");
$("#dd1").css("background-color","#2c2b2b");
$("#dd1").css("opacity","0.9");
$("#img1").show();
});        

function switch_img_intime(){          //改变图片
    HD=setInterval(function(){swicth_img(1);},5000) ;
}

function  swicth_img(arrow_state){        //1全局状态id，2左右箭头点击状态
if(intk==1){
}
 var now = IMG_SATAE;                 //保留当前
   
if(arrow_state==0){                         //倒续
   if(IMG_SATAE==1){                                
   IMG_SATAE=8;
      }else{
      IMG_SATAE=IMG_SATAE-1;
    }
}else if(arrow_state==1){                    //正续
      if(IMG_SATAE==8){                       
     IMG_SATAE=1;
    }else{ 
      IMG_SATAE=IMG_SATAE+1;
    }
}    
 else if( arrow_state==3) {                    //跳转
    IMG_SATAE=go_changeID;
 }

var     next=IMG_SATAE;   

var     nowNO="img"+(now.toString());                  
var     nextNO="img"+(next.toString());
var     nowdiv="#d"+(now.toString());
var     nextdiv="#d"+(next.toString());  
var     nowdivdd="#dd"+(now.toString());
var     nextdivdd="#dd"+(next.toString());  

changeIMG(nowNO,nextNO,now);
$(document).ready(function(){ 
$(nowdiv).css("background-color","#505050");    //还原初始色
$(nextdiv).css("background-color","#2c2b2b");   //变幻颜色
$(nowdivdd).css("background-color","#000000");  
$(nextdivdd).css("background-color","#2c2b2b");
$(nowdivdd).css("opacity","0.5"); 
$(nextdivdd).css("opacity","0.9");
});
}
function  changeIMG(a,b,now){
      var x =now.toString();

 var   bk = document.getElementById("img_boss");
 var   da ="url(http://127.0.0.1/APP/Public/IMG/0"+x+".jpg)";          

       bk.style.backgroundImage= da ;

var    hideobj=document.getElementById(a);
       hideobj.className="";
       hideobj.classList.add("imghide");
       hideobj.style.display="none";   
var     showobj=document.getElementById(b);
      showobj.style.display="block";   
      showobj.className="";
      showobj.classList.add("imgshow");
}
switch_img_intime()  //自动循环         
                      //互动状态                         
var arrowobj_L=document.getElementById("left_arrow_boss");
arrowobj_L.onclick=arrowobjL;                                    //鼠标点击左边箭头触发
var arrowobj_R=document.getElementById("right_arrow_boss");
arrowobj_R.onclick=arrowobjR;                                    //鼠标点击右边箭头触发
var IMG_obj=document.getElementById("right_boss");  




//图片鼠标悬停触发
IMG_obj.onmousemove=IMG_onmouse;
IMG_obj.onmouseout=IMG_outmouse;
//底边栏
function IMG_onmouse( ){
if(!this.contains(event.fromElement)){  
  clearInterval(HD);
document.getElementById("img_boss").setAttribute("href","sss"+IMG_SATAE);     //更改连接地址
var w= document.getElementById("down2");
   w.className=" ";
   w.classList.add("slidetoshow");                     //添加动画效果
   w.style.top="399px"; 
}  
}
function IMG_outmouse(){    
if(!this.contains(event.toElement)){  
 HD=setInterval(function(){swicth_img(1);},5000) ;
var w= document.getElementById("down2");
  w.className= " ";
  w.classList.add("slidetohide");                     //添加动画效果
  w.style.top="439px"; 
  }
}
function  arrowobjL(){    //鼠标点击左边箭头触发
swicth_img(0);
}
function  arrowobjR(){    //鼠标点击右边箭头触发
swicth_img(1);
}

function chang_down2(event){ 
if(intk==1){ 
var target = event.target|| event.srcElement;  //获取 触发ID;

var x=  (target.id).replace(/[^0-9]+/g, '');  //获取  ID中字符串数字；
go_changeID=Number(x);  
setTimeout("swicth_img(3)","50");                   //类型转换


}
}
 
/////////////////////////////////图片 end////////////////////////////////