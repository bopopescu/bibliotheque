var e,m,f,t1,t2,l1,l1h,l1hh,l2,l2h,l2hh,hpx,hhpx;
window.onload=function(){
 e=document.getElementById('hpage').style;
 m=document.getElementsByTagName('main')[0].style;
 f=document.getElementsByTagName('footer')[0].style;
 t1=document.getElementsByTagName('h1')[0].style;
 t2=document.getElementsByTagName('h2');
 l1=document.getElementById('logo');
 l1h=l1.height+'px';
 l1hh=(l1.height*.5)+'px';
 if(l2=document.getElementById('logoC')){
  l2h=l2.height+'px';
  l2hh=(l2.height*.5)+'px';
 }
 window.onresize();
 initHideShow();
}
window.onresize=function(){
 if(parseInt(window.innerWidth)<900){
  e.width=m.width=f.width='96%';
  m.padding='4pt 5pt 1pt';
  e.padding='1pt 4pt 0';
  e.fontSize='1.2em';
  l1.style.height=l1hh;
  if(l2) l2.style.height=l2hh;
  t1.fontSize='1.1em';
  t1.borderLeftWidth='25pt';
  for(var i=0;i<t2.length;i++) t2[i].style.fontSize='1.1em';
 }else{
  e.width=m.width=f.width='82%';
  m.padding='4pt 40pt 10pt';
  e.padding='10pt 40pt 0';
  e.fontSize='2.1em';
  l1.style.height=l1h;
  if(l2) l2.style.height=l2h;
  t1.fontSize='1.7em'
  t1.borderLeftWidth='45pt';
  for(var i=0;i<t2.length;i++) t2[i].style.fontSize='1.4em';
 }
}
