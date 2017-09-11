#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

SDL_Surface *foo = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;

SDL_Event event;

SDL_Surface *load_image( std::string filename ){
   //Image to be loaded
   SDL_Surface *loadedImage = NULL;
   SDL_Surface *optimizedImage = NULL;
   loadedImage = IMG_Load( filename.c_str() );

   if( loadedImage != NULL){
      optimizedImage = SDL_DisplayFormat( loadedImage );
      SDL_FreeSurface( loadedImage );

      if( optimizedImage != NULL ){
         //Map the color key
         Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF );

         //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
         SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
      }
   }

   //Return the optimized image
   return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, NULL, destination, &offset );
}

bool init()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
        return 1;
    }

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    if( screen == NULL ){
        return 1;
    }

    SDL_WM_SetCaption( "Foo says \"Hello!\"", NULL );

    return true;
}

bool load_files()
{
    background = load_image( "background.png" );

    if( background == NULL ){
        return false;
    }

    foo = load_image( "foo.png" );

    if( foo == NULL ){
        return false;
    }

    return true;
}

void clean_up()
{
    SDL_FreeSurface( background );
    SDL_FreeSurface( foo );

    SDL_Quit();
}


int main( int argc, char* args[] ){
   bool quit = false;

   if( init() == false ){
      return 1;
   }

   if( load_files() == false ){
      return 1;
   }

   apply_surface( 0, 0, background, screen );
   apply_surface( 240, 190, foo, screen );

   if( SDL_Flip( screen ) == -1){
      return 1;
   }
   
   while( quit == false ){
      while( SDL_PollEvent( &event ) ){
         if( event.type == SDL_QUIT ){
            quit = true;
         }
      }
   }

   clean_up();

   return 0;
}
