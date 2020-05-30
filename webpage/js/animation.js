function setup()
{
    createCanvas(400, 400);
    digit(0, 0, 1, 1, 0, 1, 0);
}

function draw()
{
    
}

function digit(a, b, c, d, e, f, g)
{
    segment("h", 0, 0);
    segment("v", 100, 5);
    segment("v", 0, 50);
    //segment("h", 0, 0); 
    //segment("h", 0, 0);
    //segment("h", 0, 0);
    //segment("h", 0, 0);
    //segment("h", 0, 0);
}

function segment(type="h", fill=false, x=0, y=0, height=15, width=100)
{
    if(type == "h") {
        beginShape();
            vertex(x, y+height/2);
            vertex(x+height/2, y);
            vertex(x+width-height, y);
            vertex(x+width-height/2, y+height/2);
            vertex(x+width-height, y+height);
            vertex(x+height/2, y+height);
        endShape(CLOSE);
    } else {
        let t = height;
        height = width;
        width = t;
        beginShape();
            vertex(x+width/2, y);
            vertex(x+width, y+width/2)
            vertex(x+width, y+height-width);
            vertex(x+width/2, y+height-width/2);
            vertex(x, y+height-width);
            vertex(x, y+width/2);
        endShape(CLOSE);
    }
}