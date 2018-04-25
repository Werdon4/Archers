package pl.ArcherJ.Main;

import org.jsfml.graphics.Font;
import org.jsfml.graphics.RenderWindow;
import org.jsfml.graphics.Text;
//import org.w3c.dom.events.Event;
import org.jsfml.window.event.Event;

import java.io.IOException;

public abstract class Menu implements IGameInterface{
    public abstract void MoveUp();
    public abstract void MoveDown();
    //public abstract void Display(RenderWindow myWindow);
    //public abstract Menu Listening(RenderWindow myWindow,Menu myMenu) throws IOException;

    protected Font myFont;
    protected Text[] endMessage=new Text[2];
    protected int selectedItemIndex;
}
