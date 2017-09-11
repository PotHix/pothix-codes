#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

//Screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//Surfaces
SDL_Surface *image = NULL;
SDL_Surface *screen = NULL;

//Starting with events! :)
SDL_Event event;

SDL_Surface *load_image( std::string filename ){
   //Image to be loaded
   SDL_Surface* loadedImage = NULL;

   //Optimized image
   SDL_Surface* optimizedImage = NULL;

   //load
   loadedImage = IMG_Load( filename.c_str() );

   //only with image loaded
   if( loadedImage != NULL ){
      //Create an optimized image
      optimizedImage = SDL_DisplayFormat( loadedImage );

      //Freeing the old image
      SDL_FreeSurface( loadedImage );
   }

   //Returning the optimized Image
   return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ){
   //Rectangle to hold offsets
   SDL_Rect offset;

   //Getting offsets
   offset.x = x;
   offset.y = y;

   //Let's blit the surface
   SDL_BlitSurface( source, NULL, destination, &offset );
}

bool init(){
   //initializing all SDL subsystems
   if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
      return false;
   }

   //setting up the screen
   screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

   //if i got an error setting up the screen
   if( screen == NULL ){
      return false;
   }

   //setting the window caption
   SDL_WM_SetCaption( "Testing Events", NULL );

   //If everything is fine return true
   return true;
}

bool load_files(){
   //Load image
   image = load_image( "x.png" );

   //If there was an error in loading the image
   if( image == NULL ){
      return false;
   }

   //If everything loaded fine
   return true;
}

void clean_up(){
   //Free the image
   SDL_FreeSurface( image );
   SDL_Quit();
}

int main( int argc, char* args[] ){
   //The program will wait for a quit
   bool quit = false;

   //Initializing
   if( init() == false ){
      return 1; 
   }

   //Loading my files
   if( load_files() == false ){
      return 1;
   }

   //Applying the surface to the screen
   apply_surface( 0, 0, image, screen );

   //Update the screen
   if( SDL_Flip( screen ) == -1 ){
      return 1;
   }

   //Now is time to show the image on the screen
   //while the user hasn't quit
   while( quit == false ){
      //while there's an event to handle
      while( SDL_PollEvent( &event ) ){
         //If the user has exited out the window by clicking on the X button and we need to threat this ;)
         if( event.type == SDL_QUIT ){
            //Go out
            quit = true;
         }
      }
   }

   //Free the surface and go out
   clean_up();

   return 0;
}
