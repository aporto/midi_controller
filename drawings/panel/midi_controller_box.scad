// box walls
module walls() {
    difference() {
        cube([200,140,55]);

        translate([-50,-50,28])
        rotate([8,0,0])
        cube([300,300,50]);
        
        translate([5,5,5])
        cube([190,130,55]);
    }
    
    //screw columns
    translate([5,5,0])
    cube ([5,5,35.5]);
    translate([190,5,0])
    cube ([5,5,35.5]);
    translate([5,130,0])
    cube ([5,5,55.5]);
    translate([190,130,0])
    cube ([5,5,55.5]);
}

difference() {
    walls();

    // screw holes
    translate([5,5,20])
    cylinder(r1=1.5, r2=1.5, h=165, $fn=24);         
    translate([195,5,20])
    cylinder(r1=1.5, r2=1.5, h=165, $fn=24);         
    translate([5,135,20])
    cylinder(r1=1.5, r2=1.5, h=165, $fn=24);         
    translate([195,135,20])
    cylinder(r1=1.5, r2=1.5, h=165, $fn=24);     
    
    // arduino usb connector
    translate([90,100,6])
    cube([14, 100,14]);
}




//translate([00,-10,0])
//cube([300,10,35]);

//translate([00,140,0])
//cube([300,10,55]);