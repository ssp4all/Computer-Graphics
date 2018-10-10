package teacup_javafx;
import javafx.application.Application; 
import static javafx.application.Application.launch;
import javafx.scene.Group; 
import javafx.scene.PerspectiveCamera; 
import javafx.scene.Scene; 
import javafx.scene.paint.PhongMaterial; 
import javafx.scene.shape.Cylinder; 
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class NewFXMain extends Application {  
   @Override 
   public void start(Stage stage) { 
   
    //Drawing Cylinder7 
    Cylinder cylinder7 = new Cylinder();

    //Setting the properties of the Cylinder 
    cylinder7.setHeight(130.0f); 
    cylinder7.setRadius(30.0f);   

    //Setting the position of the Cylinder 
    cylinder7.setTranslateX(100); 
    cylinder7.setTranslateY(100); 

    //rotate cylinder
//    cylinder7.setRotate(30);

    //Preparing the phong material of type Specular Power 
    PhongMaterial material7 = new PhongMaterial();  
    material7.setSpecularPower(0.1); 

    //Setting the Specular Power material to the Cylinder 
    cylinder7.setMaterial(material7);         
    //drwa handle as rectangle
    Rectangle rectangle = new Rectangle();
    rectangle.setX(130.0f); 
    rectangle.setY(60.0f); 
    rectangle.setWidth(20.0f); 
    rectangle.setHeight(70.0f);     
    
    cylinder7.setRotate(30.0);
    rectangle.setRotate(30);
    //Creating a Group object  
    Group root = new Group(cylinder7,rectangle); 
    //Creating a scene object 
    Scene scene = new Scene(root, 600, 400); 

    //Setting camera 
    PerspectiveCamera camera = new PerspectiveCamera(false); 
    camera.setTranslateX(0); 
    camera.setTranslateY(0); 
    camera.setTranslateZ(-10); 
    scene.setCamera(camera); 

    //Setting title to the Stage 
    stage.setTitle("Drawing a cup"); 

    //Adding scene to the stage 
    stage.setScene(scene); 

    //Displaying the contents of the stage 
    stage.show(); 
   }      
   public static void main(String args[]){ 
      launch(args); 
   } 
}