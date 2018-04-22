package pl.ArcherJ.Main;

import org.jsfml.graphics.Color;
import org.jsfml.graphics.Font;
import org.jsfml.graphics.RenderWindow;
import org.jsfml.graphics.Text;
import org.jsfml.system.Vector2f;
import org.jsfml.window.Keyboard;
import org.jsfml.window.event.Event;

import java.io.IOException;
import java.nio.file.Paths;

public class Options extends Menu {
    private static final int NUMBER_OF_OPTIONS_ITEMS = 9;
    int dificultyLevelIndex;
    Text[] optionTexts=new Text[NUMBER_OF_OPTIONS_ITEMS];

    Options(RenderWindow myWindow) throws IOException {
        selectedItemIndex = 0;
        dificultyLevelIndex = 1;
        myFont=new Font();
        myFont.loadFromFile(Paths.get("snap.ttf"));
        for (int i = 0; i < NUMBER_OF_OPTIONS_ITEMS; i++) {
            optionTexts[i]=new Text();
            optionTexts[i].setFont(myFont);
            optionTexts[i].setPosition(new Vector2f((float)(myWindow.getSize().x * 0.2),(float)(myWindow.getSize().y / (NUMBER_OF_OPTIONS_ITEMS + 1) * (i + 0.5))));
            optionTexts[i].setCharacterSize(50);
            optionTexts[i].setColor(Color.WHITE);
        }
        for(int i=0;i< NUMBER_OF_OPTIONS_ITEMS - 6;i++){
            optionTexts[i+4].setPosition((float)(myWindow.getSize().x * 0.6), (float)(myWindow.getSize().y / (NUMBER_OF_OPTIONS_ITEMS + 1) * (i + 1)));
        }
        optionTexts[0].setColor(Color.RED);
        optionTexts[0].setString("Muzyka");
        optionTexts[1].setString("Wiatr");
        optionTexts[2].setString("Poziom trudnosci");
        optionTexts[3].setString("Powrot");
        optionTexts[4].setString("ON");
        optionTexts[5].setString("ON");
        optionTexts[6].setString("1");
        optionTexts[7].setString("2");
        optionTexts[7].setPosition((float)(myWindow.getSize().x * 0.64), (float)(myWindow.getSize().y / (NUMBER_OF_OPTIONS_ITEMS + 1) * (3)));
        optionTexts[8].setString("3");
        optionTexts[8].setPosition((float)(myWindow.getSize().x * 0.69), (float)(myWindow.getSize().y / (NUMBER_OF_OPTIONS_ITEMS + 1) * (3)));
    }

    public void Display(RenderWindow myWindow) {
        for (int i = 0; i < NUMBER_OF_OPTIONS_ITEMS; i++) {
            myWindow.draw(optionTexts[i]);
        }
    }
    public void MoveUp(){
        if (selectedItemIndex - 1 >= 0)
        {
            optionTexts[selectedItemIndex].setColor(Color.WHITE);
            selectedItemIndex--;
            optionTexts[selectedItemIndex].setColor(Color.RED);
        }
    }
    public void MoveDown(){
        if (selectedItemIndex + 1 < NUMBER_OF_OPTIONS_ITEMS-5)
        {
            optionTexts[selectedItemIndex].setColor(Color.WHITE);
            selectedItemIndex++;
            optionTexts[selectedItemIndex].setColor(Color.RED);
        }
    }
    public Menu Listening(RenderWindow myWindow,Menu myMenu) throws IOException {
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
            switch (selectedItemIndex){
                case 0:
                {
                    System.out.println("Muzyka");
                    break;
                }
                case 1:
                {
                    System.out.println("Wiatr");
                    break;
                }
                case 2:
                {
                    System.out.println("Poziom trudnosci");
                    break;
                }
                case 3:
                    System.out.println("Powrot");
                    myMenu=new MainMenu(myWindow);
                    return myMenu;
            }
        }
        return myMenu;
    }
}
