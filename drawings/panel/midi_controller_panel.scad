circleRes = 48;


module slider(x=10, y=0)
{
    translate([x+5,y+3.5,-5])        
    cylinder(r1=1.6, r2=1.6, h=17.6, $fn=circleRes);
    
    //translate([x+5,y+3.5,2.5]) 
    //cylinder(r1=3, r2=3, h=25, $fn=circleRes);
    
    translate([x+3.5,y+7.5,-5])
    cube([3,58,15]);
    
    translate([x+5,y+65.5+3.5,-5])        
    cylinder(r1=1.6, r2=1.6, h=17.6, $fn=circleRes);
    
    //t/ranslate([x+5,y+65.5+3.5,2.5]) 
    //cylinder(r1=3, r2=3, h=25, $fn=circleRes);
    
}

module sliders() {
    slider(x=15, y=57);
    slider(x=15 + 20, y=57);
    slider(x=15 + 2 * 20, y=57);
    slider(x=15 + 3 * 20, y=57);
}

module pushbuttons() 
{
    //x=30;
    for(y = [0: 1: 1]) {
        for(x = [0: 1: 2]) {
            translate([x*30+20,y*25+15,-5])        
            cylinder(r1=8.5, r2=8.5, h=15, $fn=circleRes);    
        }
    }
}

module rotaries() 
{
    //x=30;
    for(y = [0: 1: 1]) {
        for(x = [0: 1: 2]) {
            translate([x*33+112,y*33+25,-5])        
            cylinder(r1=4, r2=4, h=15, $fn=circleRes);    
            
            translate([x*33+112,y*33+25,-13])       
            cylinder(r1=10, r2=10, h=15, $fn=circleRes);     
        }
    }
}
    
module menu() {    
    //menu
    translate([135+5,83+5,-5])       
    cylinder(r1=5.5, r2=5.5, h=15, $fn=circleRes);     
    
    //sel
    translate([150+5,83+5,-5])       
    cylinder(r1=5.5, r2=5.5, h=15, $fn=circleRes);     
    
    //opt
    translate([165+5,83+5,-5])       
    cylinder(r1=5.5, r2=5.5, h=15, $fn=circleRes);     
    
    //up
    translate([180+5,116+5,-5])       
    cylinder(r1=5.5, r2=5.5, h=15, $fn=circleRes);     
    
    //down
    translate([180+5,101+5,-5])       
    cylinder(r1=5.5, r2=5.5, h=15, $fn=circleRes);     
    
    //lcd
    translate([98,100,-5])       
    cube([75,25,15]);
}


module all () {    
    difference() {
        cube([200,140,5]);
        sliders();
        pushbuttons();
        rotaries();
        menu();
        
        //screw holes for the box
        translate([5,5,-20])
        cylinder(r1=1.8, r2=1.8, h=165, $fn=circleRes);    translate([195,5,-20])
        cylinder(r1=1.8, r2=1.8, h=165, $fn=circleRes);    translate([5,135,-20])
        cylinder(r1=1.8, r2=1.8, h=165, $fn=circleRes);    translate([195,135,-20])
        cylinder(r1=1.8, r2=1.8, h=165, $fn=circleRes);   
    }

    
   // wing(6);
    //wing(189);
}

module wing(x) {
    difference() {
        translate([x,11,-55])       
        cube([5, 118, 55]);

        translate([x-10,0,-95])       
        rotate([15,0,0])
        cube([20, 200, 55]);
    }
}

//rotate([90,0,0]) 
rotate([00,180,180]) 
all();

/*
translate([95,-80,-3])
cube([5,70,15]);

translate([95,-56,-3])
rotate([00,0,90])
cube([5,70,15]);

translate([190,-80,-3])
rotate([00,0,90])
cube([5,90,15]);
*/      

//translate([0,0,5])       
//cube([200, 100, 5]);



