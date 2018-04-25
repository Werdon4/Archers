package pl.ArcherJ.Main;

import org.jsfml.graphics.RenderWindow;

import java.io.IOException;

public interface  IGameInterface{
    void Display(RenderWindow myWindow);
    Menu Listening(RenderWindow myWindow) throws IOException;
    enum Menus{JG,DG,OPCJE,WYJSCIE,WIATR,MUZYKA,TRUDNOSC,POWROT;}

}