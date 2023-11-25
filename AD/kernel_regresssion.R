
library(lattice)

library(MASS)

x<-runif(500)
y<-sin(3*x)+0.5*rnorm(500)
z1<-sort(x)
z2<-sin(3*z1)
plot(x,y,ylim=c(-3,3))

library(tcltk)

grafica<-function(...){
  points(ksmooth(x,y,bandwidth=as.numeric(tclvalue(Slider1Value))),type="l",col="red")
}


grafica2<-function(...){
  x<<-runif(500)
  y<<-sin(3*x)+0.5*rnorm(500)
  #plot(x,y,ylim=c(-3,3))
  #points(ksmooth(x,y,bandwidth=as.numeric(tclvalue(Slider3Value))),type="l",col="red")
  #points(z1, z2,type="l",col="blue")
  
  #plot(x,y,ylim=c(-3,3))
  plot(ksmooth(x,y,bandwidth=as.numeric(tclvalue(Slider3Value))),type="l",col="red",ylim=c(-3,3))
  points(z1, z2,type="l",col="blue")
  
}             



grafica3<-function(...){
  plot(x,y,ylim=c(-3,3))
  if(as.numeric(tclvalue(Slider3Value)) > 0.005){
    points(ksmooth(x,y,bandwidth=as.numeric(tclvalue(Slider3Value))),type="l",col="red")
    points(z1, z2,type="l",col="blue")        }            }


slider1inicio=0.005;
slider1min=0.005;
slider1max=1;
slider1step=0.001


slider2inicio=1;
slider2min=0.1;
slider2max=4;
slider2step=0.1

slider3inicio=0.005;
slider3min=0.005;
slider3max=1;
slider3step=0.001



tt <- tktoplevel()
Slider1Value <- tclVar("slider1inicio")
Slider1ValueLabel <- tklabel(tt,text=as.character(tclvalue(Slider1Value)))
Slider2Value <- tclVar("slider2inicio")
Slider2ValueLabel <- tklabel(tt,text=as.character(tclvalue(Slider2Value)))
Slider3Value <- tclVar("slider3inicio")
Slider3ValueLabel <- tklabel(tt,text=as.character(tclvalue(Slider3Value)))


tkgrid(tklabel(tt,text=" cambiar h (sobrepuesto)  "),Slider1ValueLabel,tklabel(tt,text=""))
tkconfigure(Slider1ValueLabel,textvariable=Slider1Value)
slider1 <- tkscale(tt, from=slider1min, to=slider1max,
                   showvalue=F, variable=Slider1Value, resolution=slider1step, 
                   command=grafica)

tkconfigure(Slider2ValueLabel,textvariable=Slider2Value)
slider2 <- tkscale(tt, from=slider2min, to=slider2max,
                   showvalue=F, variable=Slider2Value, resolution=slider2step, 
                   command=grafica2)


tkconfigure(Slider3ValueLabel,textvariable=Slider3Value)
slider3 <- tkscale(tt, from=slider3min, to=slider3max,
                   showvalue=F, variable=Slider3Value, resolution=slider3step, 
                   command=grafica3)


tkgrid(slider1)
tkgrid(tklabel(tt,text="otra muestra "),Slider2ValueLabel)
tkgrid(slider2)
tkgrid(tklabel(tt,text="cambiar h (indep.) "),Slider2ValueLabel)
tkgrid(slider3)
tkfocus(tt)