package pl.ArcherJ.Main;
import javafx.scene.input.MouseButton;
import org.jsfml.graphics.*;
import org.jsfml.system.Vector2f;
import org.jsfml.system.Vector2i;
import org.jsfml.window.*;
import org.jsfml.window.event.*;

import java.io.IOException;

import static org.jsfml.window.VideoMode.getFullscreenModes;

public class Main {

    public static void main(String[] args) throws IOException {
        boolean aimLineChecker=false;
        Vector2f aimLineEnd=new Vector2f(0,0);
        Vector2f aimLineBegin=new Vector2f(0,0);
        RenderWindow myWindow = new RenderWindow(VideoMode.getDesktopMode(),"ArchersJ");
        myWindow.setFramerateLimit(60);

        while(myWindow.isOpen()){
            for(Event event : myWindow.pollEvents()) {
                switch(event.type){
                    case MOUSE_BUTTON_PRESSED:
                        if(event.asMouseButtonEvent().button==Mouse.Button.LEFT){
                            Vector2i pixelPos = Mouse.getPosition(myWindow);
                            Vector2f worldPos = myWindow.mapPixelToCoords(pixelPos);
                            aimLineBegin = worldPos;
                            aimLineChecker=true;
                            System.out.println("PRESS");
                        }
                        break;
                    case MOUSE_BUTTON_RELEASED:
                        if(event.asMouseButtonEvent().button==Mouse.Button.LEFT){
                            aimLineChecker=false;
                            System.out.println("RELEASE");
                        }
                        break;
                    case CLOSED:
                        myWindow.close();
                }
            }
            myWindow.clear();

            Vector2i pixelPos2 = Mouse.getPosition(myWindow);
            Vector2f worldPos2 = myWindow.mapPixelToCoords(pixelPos2);
            aimLineEnd =worldPos2;
            VertexArray lines=new VertexArray(PrimitiveType.LINE_STRIP);
            if(aimLineChecker){
                lines.add(0,new Vertex(new Vector2f(aimLineBegin.x, aimLineBegin.y)));
                lines.add(1,new Vertex(new Vector2f(aimLineEnd.x, aimLineEnd.y)));
                myWindow.draw(lines);
            }

            myWindow.display();
        }
    }
}
