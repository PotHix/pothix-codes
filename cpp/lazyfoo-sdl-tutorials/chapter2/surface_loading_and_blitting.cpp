#include "SDL/SDL.h"
#include <string> /* better than char* */

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//Surfaces that will be used
SDL_Surface *message = NULL; /* always setting pointers to NULL if they are not pointing to anything */
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

SDL_Surface *load_image( std::string filename ){
   // temporary storage for image
   SDL_Surface* loadedImage = NULL;

   //optimized image to be used
   SDL_Surface* optimizedImage = NULL;

   //load the image
   loadedImage = SDL_LoadBMP( filename.c_str() );

   //if nothing went wrong loading image
   if( loadedImage != NULL ){
      //Create an optimized image
      optimizedImage = SDL_DisplayFormat( loadedImage );

      //Free the old image
      SDL_FreeSurface( loadedImage );
   }

   //return the optimized image
   return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ){
   //Make a temporary rectangle to hold the offsets
   SDL_Rect offset;

   //Give the offsets to the rectangle
   offset.x = x;
   offset.y = y;

   //Blit the surface
   SDL_BlitSurface( source, NULL, destination, &offset );
}

int main( int argc, char* args[] ){
   //Initializing all SDL Subsystems
   if( SDL_Init( SDL_INIT_EVERYTHING ) == -1){
      return 1;
   }

   //set up screen
   screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

   //if there was an error in setting up the screen
   if( screen == NULL ){
      return 1;
   }

   //Set the main window caption
   SDL_WM_SetCaption( "Hello World", NULL );

   //Load the images
   message = load_image( "hello_world.bmp" );
   background = load_image( "background.bmp" );

   //Apply thebackground to the screen
   apply_surface( 0, 0, background, screen );
   //Apply the other image to the screen
   apply_surface( 180, 140, message, screen );

   //Update the screen
   if( SDL_Flip( screen ) == -1){
      return 1;
   }

   //Wait for 2 seconds
   SDL_Delay( 2000 );
   
   //Free the surfaces
   SDL_FreeSurface( message );
   SDL_FreeSurface( background );

   //Quit the SDL
   SDL_Quit();

   return 0;
}
