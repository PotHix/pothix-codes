DIR=converted
CURRENT_DIR=`pwd`

resize (){
   FILES_FOLDER=$CURRENT_DIR/$1

   if [ ! -d $2 ]
   then
      mkdir $2
   fi

   for i in `ls $FILES_FOLDER`
   do
      convert $FILES_FOLDER/$i -resize 1024x768 $2/$i
      echo "File $i converted"
   done
}

case $# in
   1)
      resize $1 $CURRENT_DIR/$1/$DIR
      ;;
   2)
      resize $1 $2/$DIR
      ;;
   *)
      echo "Wrong number of arguments";
      echo "Use:";
      echo "photoresize relative/path/to/pictures [relative/path/to/converted/pictures]";
      ;;
esac
