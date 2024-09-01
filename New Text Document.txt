interface DrawAPI {
   public void drawCircle(int radius);
}

class RedCircle implements DrawAPI {
   @Override
   public void drawCircle(int radius) {
      System.out.println("Drawing Red Circle With Radius : "+radius);
   }
}

class GreenCircle implements DrawAPI {
   @Override
   public void drawCircle(int radius) {
      System.out.println("Drawing Green Circle with radius :"+ radius);
   }
}

abstract class Shape{
    protected DrawAPI drawapi;
    
    protected Shape(DrawAPI drawapi)
    {
        this.drawapi=drawapi;
    }
    
    public abstract void draw();
    
}

class Circle extends Shape{
    private int radius;
    
    Circle(int radius , DrawAPI drawapi)
    {
        super(drawapi);
        this.radius=radius;
    }
    
    public void draw()
    {
        drawapi.drawCircle(radius);
    }
    
}

class BridgePattern {
    public static void main(String[] args) {
        Circle rd = new Circle(10,new RedCircle());
        Circle gr = new Circle(20,new RedCircle());
        
        rd.draw();
        gr.draw();
    }
}