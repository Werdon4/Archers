package pl.ArcherJ.Main;

import java.io.IOException;
import java.nio.file.Paths;
import java.util.Vector;
import org.jsfml.graphics.RenderWindow;
import org.jsfml.graphics.Sprite;
import org.jsfml.graphics.Texture;


public class Background {
    int spriteTabIterator;
    Texture forestTexture;
    Texture skyTexture;
    Texture grassTexture;
    Sprite mySprite;
    Vector <Sprite> tabSprite;
    
    Background(RenderWindow myWindow) throws IOException{
        spriteTabIterator = 0;
        tabSprite=new Vector<Sprite>();

        forestTexture=new Texture();
        forestTexture.loadFromFile(Paths.get("forest.jpg"));
        skyTexture=new Texture();
        skyTexture.loadFromFile(Paths.get("sky.jpg"));
        grassTexture=new Texture();
        grassTexture.loadFromFile(Paths.get("grass.jpg"));

        for (int i = 0; i < 13; i++, spriteTabIterator++)
        {
            tabSprite.add(mySprite);
            tabSprite.set(spriteTabIterator, new Sprite(forestTexture));
            tabSprite.get(spriteTabIterator).setPosition(-6 * (float)(myWindow.getSize().x) + i * (float)(myWindow.getSize().x), 0);
        }
        for (int i = 0; i < 13; i++, spriteTabIterator++)
        {
            tabSprite.add(mySprite);
            tabSprite.set(spriteTabIterator, new Sprite(skyTexture));
            tabSprite.get(spriteTabIterator).setPosition(-6 * (float)(myWindow.getSize().x) + i * (float)(myWindow.getSize().x), -(float)(myWindow.getSize().y));
        }
        for (int i = 0; i < 13; i++, spriteTabIterator++)
        {
            tabSprite.add(mySprite);
            tabSprite.set(spriteTabIterator, new Sprite(skyTexture));
            tabSprite.get(spriteTabIterator).setPosition(-6 * (float)(myWindow.getSize().x) + i * (float)(myWindow.getSize().x), -2 * (float)(myWindow.getSize().y));
        }
        for (int i = 0; i < 13; i++, spriteTabIterator++)
        {
            tabSprite.add(mySprite);
            tabSprite.set(spriteTabIterator, new Sprite(grassTexture));
            tabSprite.get(spriteTabIterator).setPosition(-6 * (float)(myWindow.getSize().x) + i * (float)(myWindow.getSize().x), (float)(myWindow.getSize().y));
        }
    }
    public void displayBackground(RenderWindow myWindow){
        for (int i = 0; i < 52; i++)
        {
            myWindow.draw(tabSprite.get(i));
        }
    }
}
