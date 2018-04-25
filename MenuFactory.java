package pl.ArcherJ.Main;

import org.jsfml.graphics.RenderWindow;

import java.io.IOException;

public class MenuFactory{
    public Menu createMenus(IGameInterface.Menus choice, RenderWindow myWindow) throws IOException {
        switch(choice){
            case JG:
                break;
            case DG:
                break;
            case OPCJE:
                return new Options(myWindow);
            case WYJSCIE:
                myWindow.close();
                break;
            case POWROT:
                return new MainMenu(myWindow);
        }
        return null;
    }
}