function hide(id){document.getElementById(id).style.display='none';}
function show(id){document.getElementById(id).style.display='block';}
function inner(id){
 var e=document.getElementById(id);
 if(e.innerHTML=='afficher') e.innerHTML='masquer';
 else e.innerHTML='afficher';
}
function unhide(id){
 var s=document.getElementById(id).style;
 if(s.display=='none'||s.display=='') s.display='block';
 else s.display='none';
}
function image(im,id){
 var s=document.getElementById(id).style;
 if(s.display=='none'||s.display=='') im.src='img/b_resume1.png';
 else im.src='img/b_resume2.png';
}
function initHideShow(){show('pmseq1');hide('pseq1');show('pmseq2');hide('pseq2');show('pmseq5');hide('pseq5');}
function zoom(e){
 var s=e.style;
 if(s.cursor=='zoom-in'||s.cursor=='') s.cursor='zoom-out';
 else s.cursor='zoom-in';
}
function hideallclass(c){
 var e=document.getElementsByClassName(c);
 for(var i=0;i<e.length;i++) e[i].style.display='none';
}
function showallclass(c){
 var e=document.getElementsByClassName(c);
 for(var i=0;i<e.length;i++) e[i].style.display='block';
}
function unhide_class(c){
 var e=document.getElementsByClassName(c);
 for(var i=0;i<e.length;i++){
  s=e[i].style;
  if(s.display=='none' || s.display=='') s.display='block';
  else s.display='none';
 }
}
function refresh(id){document.getElementById(id).refresh();}
