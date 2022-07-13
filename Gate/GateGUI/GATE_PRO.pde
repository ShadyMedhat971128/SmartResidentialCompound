 import processing.serial.*;

Serial port;
String input = "";
String output = "";
int lf = 10; // ASCII linefeed
StringList Cases;
char[] macros={'a','y','s','v','l','x','n'};
//String gueste ="visitor entry";
//String guestl ="visitor left";
//String servicel ="service left";
//String servicee ="service entry";
//String OName1 ="ahmed wael";
//String OName2 ="youssef ayman";
//String OName3 ="shady medhat";
char t;
PImage bg;
PFont gate ;
void setup() {
   size(1000,751);
  bg = loadImage("download.jpg");
  // Setup the screen for output.
  textFont(createFont("Verdana", 18));
  Cases= new StringList();
  Cases.append("ahmed wael");
  Cases.append("youssef ayman");
  Cases.append("shady medhat");
  Cases.append("visitor entry");
  Cases.append("visitor left");
  Cases.append("service entry");
  Cases.append("service left");

  // The first serial port on my mac is the Arduino so I just open that.
  // Consult the output of println(Serial.list()); to figure out which you
  // should be using.
  port = new Serial(this, Serial.list()[0], 9600);

  // Fire a serialEvent() when when a linefeed comes in to the serial port.
  port.bufferUntil(lf);
  port.write(lf);
}
//void mouseClicked()
//{
//  port.write("o");vi
    
//}
// Buffer a string until a linefeed is encountered then send it to the serial port.
void keyPressed() {
    
   if (key < 255) 
  {
    output += str(key);
    
   if (key != ENTER) 
    {
     
      for(int i=0;i<7;i++)
    {
        if(output.equals(Cases.get(i) ))
      {
        println("sending: " + output );
        port.write(macros[i]);
        output = "";
      }
      if (i==3)
      {
        t='v';
      }
      if (i==5)
      {
        t='s';
      }
    }
    
    }
   
  }
}
// Process a line of text from the serial port.
void serialEvent(Serial p) {
  input = (port.readString());
  println("received: " + input);
}

// Draw the input and ouput buffers and a little help.
void draw() {
   background(bg);
  gate = createFont("Blacksword.otf", 48);
  textFont(gate);
  stroke(125);
  fill(0);
  rect(200, 75, 570, 100);
  stroke(0);
  fill(255);
  rect(205, 80, 560, 90);
  textSize(40);
  fill(0);
  text("Welcome To The  S.Residence", 230, 130);
  fill(0);
  rect(210, 150, 550, 5);
  stroke(125);
  fill(0);
  rect(90, 190, 770, 300);
  stroke(0);
  fill(255);
  rect(95, 195, 760, 290);
  /*****************************************************************************/
  stroke(125);
  fill(0);
  rect(190, 375, 570, 60);
  stroke(0);
  fill(209);
  rect(195, 380, 560, 50);
  textFont(createFont("Verdana", 18));
  fill(0);
  textSize(32);
  switch(t)
  {
    case 'v' :
     textSize(24);
    text(input, 180, 300);
    text(output, 205, 413);
    break;
    case 's':
    textSize(24);
    text(input, 180, 300);
    text(output, 205, 413);
    break;
    default :
    text(input, 300, 300);
    text(output, 205, 413);
  
    break;
   }
  }
