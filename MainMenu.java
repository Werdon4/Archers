package pl.ArcherJ.Main;
import org.jsfml.graphics.*;
import org.jsfml.system.Vector2f;
import org.jsfml.window.Keyboard;

import java.io.IOException;
import java.nio.file.Paths;




public class MainMenu extends Menu  {

    private static final int NUMBER_OF_MENU_ITEMS = 4;
    Text[] menuTexts=new Text[NUMBER_OF_MENU_ITEMS];

    MainMenu(RenderWindow myWindow) throws IOException {
        selectedItemIndex = 0;
        myFont=new Font();
        myFont.loadFromFile(Paths.get("snap.ttf"));
        for (int i = 0; i < NUMBER_OF_MENU_ITEMS; i++)
        {
            menuTexts[i]=new Text();
            menuTexts[i].setFont(myFont);
            menuTexts[i].setPosition(new Vector2f((float)(myWindow.getSize().x * 0.4),(float)(myWindow.getSize().y / (NUMBER_OF_MENU_ITEMS + 1) * (i + 0.5))));
            menuTexts[i].setCharacterSize(50);
            menuTexts[i].setColor(Color.WHITE);
        }

        menuTexts[0].setColor(Color.RED);
        menuTexts[0].setString("Jeden gracz");
        menuTexts[1].setString("Dwóch graczy");
        menuTexts[2].setString("Ustawienia");
        menuTexts[3].setString("Wyjscie");
        }


    public void Display(RenderWindow myWindow){
        for (int i = 0; i < NUMBER_OF_MENU_ITEMS; i++)
        {
            myWindow.draw(menuTexts[i]);
        }
    }

    public Menu Listening( RenderWindow myWindow) throws IOException {

        if(Keyboard.isKeyPressed(Keyboard.Key.ESCAPE)){
                myWindow.close();
        }
        if(Keyboard.isKeyPressed(Keyboard.Key.UP)){
            this.MoveUp();
        }
        if(Keyboard.isKeyPressed(Keyboard.Key.DOWN)){
            this.MoveDown();
        }
        if(Keyboard.isKeyPressed(Keyboard.Key.RETURN)){
            MenuFactory myMenus=new MenuFactory();
            switch (selectedItemIndex){
                case 0:
                {
                    System.out.println("Jeden gracz");
                    break;
                }
                case 1:
                {
                    System.out.println("Dwoch graczy");
                    break;
                }
                case 2:
                {
                    System.out.println("Ustawienia");
                    myMenus.createMenus(Menus.OPCJE,myWindow);
                    return new Options(myWindow);
                    //break;
                }
                case 3:
                    myWindow.close();
                    break;
            }
        }
        return this;
    }

    public void MoveUp(){
        if (selectedItemIndex - 1 >= 0)
        {
            menuTexts[selectedItemIndex].setColor(Color.WHITE);
            selectedItemIndex--;
            menuTexts[selectedItemIndex].setColor(Color.RED);
        }
    }
    public void MoveDown(){
        if (selectedItemIndex + 1 < NUMBER_OF_MENU_ITEMS)
        {
            menuTexts[selectedItemIndex].setColor(Color.WHITE);
            selectedItemIndex++;
            menuTexts[selectedItemIndex].setColor(Color.RED);
        }
    }
}
