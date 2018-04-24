package pl.ArcherJ.Main;
import org.jsfml.audio.*;
import org.jsfml.graphics.*;
import org.jsfml.window.*;
import org.jsfml.window.event.*;
import org.jsfml.internal.*;
import org.jsfml.system.*;

import java.io.Console;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        RenderWindow myWindow = new RenderWindow(new VideoMode(1920,1080),"ArchersJ");
        myWindow.setFramerateLimit(60);
        Menu myMenu=new MainMenu(myWindow);
        Background myBackground = new Background(myWindow);

        while(myWindow.isOpen()){
            for(Event event : myWindow.pollEvents()) {
                myMenu=myMenu.Listening( myWindow,myMenu);
            }
            myWindow.clear();
            myBackground.displayBackground(myWindow);
            myMenu.Display(myWindow);
            myWindow.display();
        }
    }
}
