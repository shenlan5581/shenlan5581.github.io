 

  //jquery 
   $(document).ready(function(){ 
   
   $("#state").slideUp(2000);
   
 ////输出表单////             
   					
   $(".register>*").hide();
   $(".reset_password>*").hide();

   $("#login").click(function(){
   $("#state>*").hide("slow");
   $(".register>*").hide("slow");
   $(".reset_password>*").hide("slow");  
   $(".login>*").show("slow");
  
   });  
   
    $("#register").click(function(){ 
  	$("#state>*").hide("slow");
    $(".reset_password>*").hide("slow");
  	$(".login>*").hide("slow");
  	$(".register>*").show("slow");
   });  
 
     $("#reset_password").click(function(){ 
     $("#state>*").hide("slow");
     $(".login>*").hide("slow");
     $(".register>*").hide("slow"); 
     $(".reset_password>*").show("slow");
   });   	
});
  $(document).ready(function(){ 

    
  $("#k_content").hide();

  $("#user_state").mousemove(function(){
  $("#k_content").show();
  $("#k_content").animate({
  display:'block',  
  width:'400px', 
  height: '120px',
  position:'fixed',
  left:'100px',top:'120px',
  opacity:'.9'}); 
}) ;

 $("#k_content").mouseleave(function(){
  $("#k_content").animate({
  display:'block', 
  width:'1px', 
  height: '1px',
  position:'fixed',
  left:'100px',top:'120px',
  opacity:'.5'}) 
  .hide('slow');
 });

 $("#k_content").mousemove(function(){
 
 $("#slide").slideDown("slow");
 
 
  });
 
 });

 //header   
 $(document).ready(function(){
  $("#search").focus(function(){
  $(".search_boss").css("border-color","#c78814");//搜索边框  
});
  $("#search").blur(function(){
  $(".search_boss").css("border-color","#a2a2a2");
 });
 
$(".classification").mousemove(function(){           
  $(".classification").css("background-color","##eeeeee ");  
});
$(".classification").mouseleave(function(){             //分类标题
  $(".classification").css("background-color","#f9f9f9");
});
 
 $(".search_image").mousemove(function(){           //放大镜IMG
  $(".search_image").attr("src","http://127.0.0.1/APP/Public/IMG/searchb.jpg");   
});
$(".search_image").mouseleave(function(){             
  $(".search_image").attr("src","http://127.0.0.1/APP/Public/IMG/search.jpg");
});
$("#content").mousemove(function(){                      //分类元素边框隐藏  透明边框
  $(this).css("border-color","#d8d8d8");  
});
$("#content").mouseleave(function(){
  $(this).css("border-color","transparent");  
});
 
 });