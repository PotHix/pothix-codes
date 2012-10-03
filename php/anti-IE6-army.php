<?php
/* This is the code from my simple wordpress plugin from 2009.
 * The main idea for this plugin was help to kill internet explorer 6
 * and fortunately I think this problem is really is not so big today and
 * I'll just  keep the code here for the sake of history.
 */


/*
Plugin Name: anti-IE6-army
Plugin URI: http://wordpress.org/extend/plugins/anti-ie6-army
Description: anti-IE6-army is a plugin that insert a Javascript on your page head to inform your IE6 ( and <= ) visitors that they are using a old and insecure browser.
Author: Willian Molinari
Version: 1.2.0
Author URI: http://pothix.com/blog
 */


/*
 * Function to prepare Anti-IE6-Army for battle
 */
function prepare_army() {
   add_action('admin_menu', 'choose_soldier_submenu_include');
   soldier_verify();
}

/*
 * Verify if have a option into the options table, and include in negative case
 */
function soldier_verify(){
   /* Soldier to use */
   if(!get_option('anti-ie6-soldier')){
      add_option("anti-ie6-soldier", '0', '', 'yes');
   }

   /* What language you soldier should speak */
   if(!get_option('anti-ie6-soldier-language')){
      add_option("anti-ie6-soldier-language", '0', '', 'yes');
   }

   /*
    * LANGUAGES
    *
    * 0 - English
    * 1 - Portuguese
    * 2 - Deutsch Du
    * 3 - Deutsch Sie
    * 4 - Spanish
    * 5 - Franch
    * 6 - Catalan
    * 7 - Galego
    * 8 - Magyar
    * 9 - Japenese
    */
}

/*
 * Add a submenu in the plugins menu
 */
function choose_soldier_submenu_include() {
   if(function_exists('add_submenu_page')){
      add_submenu_page('plugins.php', __('Anti IE6 army - Choose a Soldier'), __('Anti IE6 army'), 'manage_options', '', 'choose_soldier_page');
   }
}

/*
 * This is the page to choose your soldier to block IE6
 */
function choose_soldier_page() {
   /* initializing blank arrays to use */
   $soldier_checked = array("","","","");
   $language_selected = array("","","","","","","","","","");

   if ( isset($_POST['submit']) ) {
      update_option('anti-ie6-soldier', $_POST['soldier']);
      update_option('anti-ie6-soldier-language', $_POST['language']);
   }

   $soldier_checked[get_option('anti-ie6-soldier')] = 'checked="checked"';
   $language_selected[get_option('anti-ie6-soldier-language')] = 'selected="selected"';

   if ( !empty($_POST ) ){
      echo '<div id="message" class="updated fade"><p><strong>'; _e('Options saved.'); echo '</strong></p></div>';
   }

   /* Draw the form to choose what soldier will fight for you */
   echo '<div class="wrap">
            <h2>Anti IE6 army - Choose a Soldier"</h2>
            <div class="narrow">
               <form action="" method="post" id="choose-soldier" style="margin: auto; width: 450px; ">
                  <p>What language your soldier should speak?</p>
                  <select name="language" id="language" style="float:left">
                     <option value="0" ' . $language_selected[0] . '>English</option>
                     <option value="1" ' . $language_selected[1] . '>Português</option>
                     <option value="2" ' . $language_selected[2] . '>Deutsch Du</option>
                     <option value="3" ' . $language_selected[3] . '>Deutsch Sie</option>
                     <option value="4" ' . $language_selected[4] . '>Español</option>
                     <option value="5" ' . $language_selected[5] . '>Français</option>
                     <option value="6" ' . $language_selected[6] . '>Català</option>
                     <option value="7" ' . $language_selected[7] . '>Galego</option>
                     <option value="8" ' . $language_selected[8] . '>Magyar</option>
                     <option value="9" ' . $language_selected[9] . '>Japenese</option>
                  </select>
                  <p style="color:#F00"> ( If your soldier dont speak this language he will speak <b>English</b> )</p>
                  <p>Here you choose which soldier of your army will lead the battle against IE6</p>
                  <input type="radio" value="0" name="soldier"' . $soldier_checked[0] . '/> Crossbrowser <br />
                  <input type="radio" value="1" name="soldier"' . $soldier_checked[1] . '/> End6 <br />
                  <input type="radio" value="3" name="soldier"' . $soldier_checked[3] . '/> End6 Sarcasm <br />
                  <input type="radio" value="2" name="soldier"' . $soldier_checked[2] . '/> Stop IE6 <br />
                  <input type="radio" value="4" name="soldier"' . $soldier_checked[4] . '/> Update IE6 <br />
                  <input type="radio" value="5" name="soldier"' . $soldier_checked[5] . '/> Update Your Browser <br />
                  <p class="submit"><input type="submit" name="submit" value="Call Soldier" /></p>
               </form>
            </div>
         </div>';
}

/*
 * print the crossbrowser script
 * Created by Imasters Team: http://imasters.uol.com.br/crossbrowser/en/
 */
function crossbrowser_js(){
   $languages = array("en/","NATIVE");
   echo "\n".'<!-- Anti IE6 Army - Soldier Call -->';
   echo "\n".'<script src="http://imasters.uol.com.br/crossbrowser/' . soldier_language($languages) . 'fonte.js" type="text/javascript"></script>'."\n";
}

/*
 * print the end6 script
 * Created by Miquel Hudin: http://www.end6.org/eng/faq/
 */
function end6_js(){
   $languages = array("eng","por","deu_du","deu_sie","esp","fra","cat","gal","hun","jap");
   echo "\n".'<!-- Anti IE6 Army - Soldier Call -->';
   echo "\n".'<script src="http://www.end6.org/js/' . soldier_language($languages) . '_end6.js" type="text/javascript"></script>'."\n";
}

/*
 * print the end6 sarcasm script
 * created by Canha from http://digitalpaperweb.com.br based on End6
 */
function end6_sarcasm_js(){
   $languages = array("_eng","NATIVE");
   echo "\n".'<!-- Anti IE6 Army - Soldier Call -->';
   echo "\n".'<script src="http://digitalpaperweb.com.br/end6sarc' . soldier_language($languages) . '.js" type="text/javascript"></script>'."\n";
}

/*
 * print the stop ie6 script
 * Created by this guys: http://www.stopie6.org/about
 */
function stop_ie6_js(){
   /* StopIE6 just have one version...in English */
   /* $languages = array("eng"); */
   echo "\n".'<!-- Anti IE6 Army - Soldier Call -->';
   echo "\n".'<script src="http://www.stopie6.org/js/Detect.js" type="text/javascript"></script>';  /* Detect */
   echo "\n".'<script src="http://www.stopie6.org/js/tolerant/StopIE6.js" type="text/javascript"></script>'."\n"; /* Tolerant */
}


/*
 * print the stop ie6 script
 * Created by this guys: http://www.stopie6.org/about
 */
function update_ie6_js(){
   /* TODO: Include multi-language */
   echo "\n".'<!-- Anti IE6 Army - Soldier Call -->';
   echo "\n".'<!--[if IE 6]>';
   echo "\n".'   <script type="text/javascript">';
   echo "\n".'   /*Load jQuery if not already loaded*/ if(typeof jQuery == "undefined"){ document.write("<script type=\"text/javascript\"   src=\"http://ajax.googleapis.com/ajax/libs/jquery/1.3.2/jquery.min.js\"></"+"script>"); var __noconflict = true; }';
   echo "\n".'   var IE6UPDATE_OPTIONS = {';
   echo "\n".'      icons_path: "http://static.ie6update.com/hosted/ie6update/images/"';
   echo "\n".'   }';
   echo "\n".'   </script>';
   echo "\n".'   <script type="text/javascript" src="http://static.ie6update.com/hosted/ie6update/ie6update.js"></script>';
   echo "\n".'<![endif]-->';
}

/*
 * print the updateyourbrowser script
 * created by Richard Barros from http://www.richardbarros.com.br/blog/
 */
function updateyourbrowser_js(){
   $languages = array("uyb","asn"); /* uyb = English and asn = Portuguese */
   echo "\n".'<!-- Anti IE6 Army - Soldier Call -->';
   echo "\n".'<script src="http://updateyourbrowser.net/' . soldier_language($languages) . '.js" type="text/javascript"></script>'."\n";
}

/*
 * Return what language soldier will speak
 * If he can't speak the chosen language, he will speak your native language...ENGLISH! =)
 */
function soldier_language($soldier_speak){
   $chosen_language = get_option('anti-ie6-soldier-language');
   if($soldier_speak[$chosen_language]){
      return ( $soldier_speak[$chosen_language] == 'NATIVE' ) ? "" : $soldier_speak[$chosen_language]; /* NATIVE is used in case of no preffix or suffix to a native language */
   }else{
      return $soldier_speak[0];
   }
}


/*
 * Add the chosen option at blog <head>
 */
function add_javascript_at_head($chosen_soldier){
   switch ($chosen_soldier) {
   case 0:
      add_action('wp_head', 'crossbrowser_js');
      break;

   case 1:
      add_action('wp_head', 'end6_js');
      break;

   case 2:
      add_action('wp_head', 'stop_ie6_js');
      break;

   case 3:
      add_action('wp_head', 'end6_sarcasm_js');

   case 4:
      add_action('wp_head', 'update_ie6_js');

   case 5:
      add_action('wp_head', 'updateyourbrowser_js');
   }
}

/* Let's prepare our army to battle! */
add_action('init', 'prepare_army');

/* And now, call our leader */
$chosen_soldier = get_option('anti-ie6-soldier');
add_javascript_at_head($chosen_soldier);
?>
