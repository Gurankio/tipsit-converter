var canvas;

function setup()
{
     //var arduino = ["1110111", "0000101", "0111101", "0011100", "0010000", "0010101", "0011101"];
     var hello = ["0010111", "1001111", "0001110", "0001110", "1111110"];
    //createDigits(0.4, hello);
}

function createDigits(percentage, digits)
{
    canvas = createCanvas(0.7*windowWidth, 100);
    canvas.parent(document.getElementById("p5-canvas"));
    scale(percentage);

    digit(0, 0, digits[0]);
    for(let j = 1; j < digits.length; j++)
        digit(120, 0, digits[j]);
}

function digit(newX=0, newY=0, bits="0000000")
{
    let border = true;
    translate(newX, newY);
    segment("h", Boolean(Number(bits[0])), border, 9, 0);
    segment("v", Boolean(Number(bits[1])), border, 96, 9);
    segment("v", Boolean(Number(bits[2])), border, 96, 103);
    segment("h", Boolean(Number(bits[3])), border, 9, 189);
    segment("v", Boolean(Number(bits[4])), border, 0, 103);
    segment("v", Boolean(Number(bits[5])), border, 0, 9);
    segment("h", Boolean(Number(bits[6])), border, 9, 95);
}

function segment(type="h", on=false, border=false, x=0, y=0, height=15, width=100)
{
    stroke(color(255, 255, 255));
    
    if(on) {
        fill(color("#FF8811"));
    } else {
        fill(color("#e9e9e9"));
    }
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