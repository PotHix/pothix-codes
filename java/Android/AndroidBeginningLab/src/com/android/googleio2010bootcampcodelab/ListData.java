package com.android.googleio2010bootcampcodelab;

import java.lang.reflect.Field;
import java.util.Date;
import java.util.HashMap;
import java.util.LinkedList;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.Uri;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.TextView;
import android.widget.Toast;

/**
 * A simple class demonstrating the use of a ListView in a standard activity.  It adds
 * the string associated with the EXTRA_TEXT field of the incoming Intent to the displayed list,
 * and allows the user to make various web searches. 
 * @see <a href="http://developer.android.com/reference/android/app/Activity.html">Activity</a>
 * @see <a href="http://developer.android.com/reference/android/app/ListActivity.html">ListActivity</a>
 * @see <a href="http://developer.android.com/reference/android/widget/ListView.html">ListView</a>
 */
public class ListData extends Activity implements AdapterView.OnItemClickListener{

	/**
	 * We use a SimpleAdapter, which takes a List of Maps.  We choose to implement this using LinkedList
	 * and HashMap.Copy of BeginningLab-Handout.  The following should NEVER BE DONE in your Android
	 * applications.  Don't make use of non-final static members in your activity classes.  Instead,
	 * this sort of thing could be done in an application class.  Why haven't we done it here?
	 * Because we don't want to have to introduce and explain application classes.  Besides, a future
	 * version of this application should store this data in some non-volatile storage such as a
	 * SQLite database, so this is only temporary.
	 */
	static LinkedList<HashMap<String, String>> queryList = new LinkedList<HashMap<String, String>>();
	
	/**
	 * Called when the activity is starting. We use this function to set the content
	 * view that contains our list view, read data from the intent, display a toast
	 * that the data is being added to the list, create our SimpleAdapter, and attach
	 * it to our ListView.
	 * @param savedInstanceState If the activity is being re-initialized after previously 
	 * being shut down then this Bundle contains the data it most recently supplied 
	 * in onSaveInstanceState(Bundle). Note: Otherwise it is null.
	 * @see <a href="http://developer.android.com/reference/android/app/Activity.html#onCreate(android.os.Bundle)">Activity:onCreate</a>
	 */
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		setContentView(R.layout.listlayout);

		/**
		 * Step 04: Uncomment the following lines to pull the search
		 * string from the intent and add it to the queryList of HashMaps
		 * that backs the SimpleAdapter.
		 */
		Intent intent = getIntent();
		CharSequence queryString = intent
				.getCharSequenceExtra(Intent.EXTRA_TEXT);
		if (null != queryString) {
			HashMap<String, String> map = new HashMap<String, String>();
			map.put(QUERY_TEXT, queryString.toString());
			map.put(QUERY_DATE, new Date().toLocaleString());
			queryList.addFirst(map);
			/*
			 * The following line makes sure that the text is only
			 * added to the list once, even if the onCreate method
			 * gets called multiple times.  This can happen when
			 * the configuration changes, which can happen if the
			 * user opens the keyboard or changes the orientation.
			 */
			intent.removeExtra(Intent.EXTRA_TEXT);
			Toast.makeText(
					this,
					getString(R.string.query_added_toast, queryString
							.toString()), Toast.LENGTH_SHORT).show();
			while (queryList.size() > MAX_LIST_SIZE) {
				queryList.removeLast();
			}
		}
		
		/**
		 * Step 05: Uncomment the following lines to create the SimpleAdapter
		 * view, tie it to the list view, and add an onItemClickListener.
		 */
		
		SimpleAdapter sAdapter = new SimpleAdapter(this, queryList,
				android.R.layout.two_line_list_item, 
				new String[] { QUERY_TEXT, QUERY_DATE }, 
				new int[] { android.R.id.text1, android.R.id.text2 });
		ListView lv = (ListView) findViewById(android.R.id.list);
		lv.setAdapter(sAdapter);
		
		/**
		 * Step 06: Uncomment the following line to register our class as an
		 * onItemClickListener for our list view
		 */
		
		lv.setOnItemClickListener(this);

		/**
		 * Bonus 01-1: Uncomment the following lines to attach a context menu for the
		 * Activity.
		 */
		
		lv.setOnCreateContextMenuListener(this);
		super.onCreate(savedInstanceState);
	}	
	
	/**
	 * The onCreateContextMenu function gives the user the complete list of queries available
	 * for each list item.
	 * @param menu The context menu that is being built
	 * @param v The view for which the context menu is being built
	 * @param menuInfo 	Extra information about the item for which the context menu should be shown. This information will vary depending on the class of v. 
	 * @see <a href="http://developer.android.com/reference/android/app/Activity.html#onCreateContextMenu(android.view.ContextMenu,%20android.view.View,%20android.view.ContextMenu.ContextMenuInfo)">onCreateContextMenu</a>
	 */
	@Override
	public void onCreateContextMenu(ContextMenu menu, View v,
			ContextMenu.ContextMenuInfo menuInfo) {
		/**
		 * Bonus 01-2: Uncomment the following line to inflate the menu resource to create
		 * the context menu.
		 */
		getMenuInflater().inflate(R.menu.search_context_menu, menu);
		super.onCreateContextMenu(menu, v, menuInfo);
	}
	
	/**
	 * The onContextItemSelected function executes the query associated with the selected MenuItem.
	 * @param item the MenuItem that was selected.  The list item that was selected can be found
	 * in the AdapterView.AdapterContextMenuInfo function.
	 * @see <a href="http://developer.android.com/reference/android/widget/ListAdapter.html">ListAdapter</a>
	 * @see <a href="http://developer.android.com/reference/android/widget/AdapterView.html">AdapterView</a>
	 */
	@Override
	public boolean onContextItemSelected(MenuItem item) {
		/**
		 * Bonus 01-3: Uncomment the following lines to act on a click from the context or
		 * long-press pop-up menu.
		 */
		AdapterView.AdapterContextMenuInfo menuInfo = (AdapterView.AdapterContextMenuInfo) item
				.getMenuInfo();
		runQueryForListItem(menuInfo.targetView, item.getItemId());
		return super.onContextItemSelected(item);
	}

	/**
	 * These String values are used as keys in the row hashmaps for use by
	 * SimpleAdapter.
	 */
	static final String QUERY_TEXT = "QT";
	static final String QUERY_DATE = "QD";

	static final int MAX_LIST_SIZE = 10;

	/**
	 * Get an "I'm Feeling Lucky" Google http Uri for the search text. This is
	 * not in any way an officially-supported way of doing this, but it is fun
	 * for demo purposes. It works as of today, but may not work as of tomorrow
	 * 
	 * @param searchText
	 * @return Uri containing the query
	 */
	private Uri getImFeelingLuckyUri(CharSequence searchText) {
		return Uri.parse("http://www.google.com/search?hl=en&q="
				+ Uri.encode(searchText.toString(), null) + "&btnI="
				+ Uri.encode("I'm Feeling Lucky"));
	}
	
	/**
	 * Get a Bing http Uri for the search text.
	 * 
	 * @param searchText
	 * @return Uri containing the query
	 */
	private Uri getBingUri(CharSequence searchText) {
		return Uri.parse("http://www.bing.com/search?q="
				+ Uri.encode(searchText.toString(), null));
	}

	/**
	 * Get an Ask http Uri for the search text.
	 * 
	 * @param searchText
	 * @return Uri containing the query
	 */
	private Uri getAskUri(CharSequence searchText) {
		return Uri.parse("http://www.ask.com/web?q="
				+ Uri.encode(searchText.toString(), null));
	}	
	
	/**
	 * Get a Google maps http Uri for the search text. This is not in any way an
	 * officially-supported way of doing this, but it is fun for demo purposes.
	 * It works as of today, but may not work as of tomorrow
	 * 
	 * @param searchText
	 * @return Uri containing the query
	 */
	private Uri getMapsUri(CharSequence searchText) {
		return Uri.parse("http://maps.google.com/maps?q="
				+ Uri.encode(searchText.toString(), null));
	}

	/**
	 * Get an Android reference http Uri for the search text. This is not in any
	 * way an officially-supported way of doing this, but it is fun for demo
	 * purposes. It works as of today, but may not work as of tomorrow
	 * 
	 * @param searchText
	 * @return Uri containing the query
	 */
	private Uri getAndroidReferenceUri(CharSequence searchText) {
		return Uri.parse("http://developer.android.com/search.html#q="
				+ Uri.encode(searchText.toString()) + "&t=0");
	}

	/**
	 * Get a Google code search http Uri for the search text, filtering on the
	 * android base framework package. This is not in any way an
	 * officially-supported way of doing this, but it is fun for demo purposes.
	 * It works as of today, but may not work as of tomorrow
	 * 
	 * @param searchText
	 * @return Uri containing the query
	 */
	private Uri getAndroidSourceUri(CharSequence searchText) {
		return Uri
				.parse("http://www.google.com/codesearch?as_q="
						+ Uri.encode(searchText.toString())
						+ "&as_package="
						+ Uri
								.encode("git://android.git.kernel.org/platform/frameworks/base.git"));
	}

	/**
	 * Get a Google image search http Uri for the search text. This is not in
	 * any way an officially-supported way of doing this, but it is fun for demo
	 * purposes. It works as of today, but may not work as of tomorrow
	 * 
	 * @param searchText
	 * @return Uri containing the query
	 */
	private Uri getImagesUri(CharSequence searchText) {
		return Uri.parse("http://www.google.com/images?q="
				+ Uri.encode(searchText.toString()));
	}

	/**
	 * Given a list item, pull out the text from the field android.R.id.text1
	 * and run the query matching the passed in id. This calls the get[type]Uri
	 * functions, and then builds an ACTION_VIEW intent.
	 * 
	 * @param listItem
	 *            View that contains the text1 that contains the search query
	 * @param queryType
	 *            int id of the query to perform
	 */
	private void runQueryForListItem(View listItem, int queryType) {
		ViewGroup vg = (ViewGroup) listItem;
		TextView queryStringView = (TextView) vg
				.findViewById(android.R.id.text1);
		CharSequence cs = queryStringView.getText();
		if (null != cs && cs.length() != 0) {
			Uri searchUri = null;
			switch (queryType) {
			case R.id.lucky_search:
				searchUri = getImFeelingLuckyUri(cs);
				break;
			case R.id.bing_search:
				searchUri = getBingUri(cs);
				break;
			case R.id.ask_search:
				searchUri = getAskUri(cs);
				break;
			case R.id.maps_search:
				searchUri = getMapsUri(cs);
				break;
			case R.id.image_search:
				searchUri = getImagesUri(cs);
				break;
			case R.id.android_reference_search:
				searchUri = getAndroidReferenceUri(cs);
				break;
			case R.id.android_source_search:
				searchUri = getAndroidSourceUri(cs);
				break;
			}
			if (null != searchUri) {
				Intent intent = new Intent(Intent.ACTION_VIEW, searchUri);
				startActivity(intent);
			}
		}

	}

	/**
	 * Initialize the contents of the Activity's standard options menu. Menu items are placed into menu. 
	 * @param menu The options menu in which you place your items.
	 * @return true for the menu to be displayed, false to not show the menu
	 * @see <a href="http://developer.android.com/reference/android/app/Activity.html#onCreateOptionsMenu(android.view.Menu):>onCreateOptionsMenu</a>
	 */
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		/**
		 * Bonus 02-1: Uncomment the following lines to make a "Preferences"
		 * option appear in the options menu (which appears when the menu
		 * button is pressed), and have that option call the SearchPreferences
		 * activity. Make sure to also follow Bonus step 02-2 and uncomment out
		 * the preferences activity declaration in the AndroidManifest XML file.
		 */
		menu.add(R.string.preferences).setIcon(
				android.R.drawable.ic_menu_preferences).setIntent(
				new Intent(this, SearchPreferences.class));
		return super.onCreateOptionsMenu(menu);
	}

	/**
	 * This method uses reflection to dynamically query the Android R.id class
	 * for the integer value of the field matching the name of searchIDString.
	 * @param searchIdString the name of the field within R.id.  This must match
	 * exactly otherwise an exception will occur.
	 * @return the id of the resource
	 * @throws Exception if the field is not found
	 */
	/**
	 * Advanced topic:  We can use reflection to automate what getIdOfSearch
	 * below does.
	 */
//	private int useReflectionToGetId(String searchIdString) throws Exception {
//		Field field = R.id.class.getDeclaredField(searchIdString);
//		return field.getInt(null);
//	}

	/**
	 * This method maps the searchIdString to an integer id for the search.
	 * @param searchIdString the name of the field within R.id.  This must match
	 * exactly otherwise an exception will occur.  But... where do the id's come
	 * from?  The search_context_menu xml file.  Id's can come from anywhere.
	 * @return the id of the resource
	 * @throws Exception if the field is not found
	 */
	private int getIdOfSearch(String searchIdString) throws Exception {
		if ( searchIdString.equals("lucky_search") ) 
			return R.id.lucky_search;
		if ( searchIdString.equals("bing_search") ) 
			return R.id.bing_search;
		if ( searchIdString.equals("ask_search") ) 
			return R.id.ask_search;
		if ( searchIdString.equals("maps_search") )
			return R.id.maps_search;
		if ( searchIdString.equals("image_search") )
			return R.id.image_search;
		if ( searchIdString.equals("android_reference_search" ) )
			return R.id.android_reference_search;
		if ( searchIdString.equals("android_source_search") )
			return R.id.android_source_search;
		throw new Exception("Search ID not Found");
	}
	
	/**
	 * Callback method to be invoked when an item in this AdapterView has been clicked.
	 * Implementers can call getItemAtPosition(position) if they need to access the data
	 * associated with the selected item.
	 * @param listView The AdapterView where the click happened.
	 * @param listItem The view within the AdapterView that was clicked (this will be a view provided by the adapter)
	 * @param position The position of the view in the adapter.
	 * @param id The row id of the item that was clicked. 
	 * @see <a href="http://developer.android.com/reference/android/widget/AdapterView.OnItemClickListener.html#onItemClick(android.widget.AdapterView%3C?%3E,%20android.view.View,%20int,%20long)">onItemClick</a>
	 */
	public void onItemClick(AdapterView<?> listView, View listItem, int position, long id) {
		/**
		 * Step 07: Handle the onItemClick, and have the application launch
		 * the web browser using the intent created in runQueryForListItem.  Note that
		 * this method uses reflection to go from the string associated with the list item
		 * to the ID associated with the query. Uncomment out the following lines.
		 */
		SharedPreferences pref = PreferenceManager
				.getDefaultSharedPreferences(ListData.this);
		String searchIdString = pref.getString(
				getString(R.string.default_search), "lucky_search");
		try {
			int fieldId = getIdOfSearch(searchIdString);
			runQueryForListItem(listItem, fieldId);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
