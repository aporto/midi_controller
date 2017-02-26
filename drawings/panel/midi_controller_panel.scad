


module slider(x=10, y=0)
{
    translate([x+5,y+3.5,-5])        
    cylinder(r1=1.5, r2=1.5, h=15, $fn=24);
    
    translate([x+3.5,y+7.5,-5])
    cube([3,58,15]);
    
    //translate([x+5,y+65,-5])        
    translate([x+5,y+65.5+3.5,-5])        
    cylinder(r1=1.5, r2=1.5, h=15, $fn=24);
    
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
            translate([x*20+38,y*25+15,-5])        
            cylinder(r1=8, r2=8, h=15, $fn=24);    
        }
    }
}

module rotaries() 
{
    //x=30;
    for(y = [0: 1: 1]) {
        for(x = [0: 1: 2]) {
            translate([x*33+112,y*33+25,-5])        
            cylinder(r1=4, r2=4, h=15, $fn=24);    
            
            translate([x*33+112,y*33+25,-13])       
            cylinder(r1=10, r2=10, h=15, $fn=24);     
        }
    }
}
    
module menu() {    
    //menu
    translate([135+5,83+5,-5])       
    cylinder(r1=5, r2=5, h=15, $fn=24);     
    
    //sel
    translate([150+5,83+5,-5])       
    cylinder(r1=5, r2=5, h=15, $fn=24);     
    
    //opt
    translate([165+5,83+5,-5])       
    cylinder(r1=5, r2=5, h=15, $fn=24);     
    
    //up
    translate([180+5,116+5,-5])       
    cylinder(r1=5, r2=5, h=15, $fn=24);     
    
    //down
    translate([180+5,101+5,-5])       
    cylinder(r1=5, r2=5, h=15, $fn=24);     
    
    //lcd
    translate([100,100,-5])       
    cube([72,25,15]);
}

rotate([180,0,0]) 
    
difference() {
    cube([200,140,5]);
    sliders();
    pushbuttons();
    rotaries();
    menu();
}


//translate([0,0,5])       
//cube([200, 100, 5]);



