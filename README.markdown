Pages Font Setter
-------------
*Just a wrapper / rewrite of [jjgod's work](http://blog.jjgod.org/2009/03/03/reformat-pages-with-appscript/).*

**PLEASE MAKE A COPY OF YOUR DOCUMENT BEFORE YOU TRY THIS!**

PagesFontSetter is a utility that help you set the fonts for CJK or Latin characters separately in Pages document.

Requirements
-----------
* iWork 09+
* Mac OS X 10.5+

Issues
-----------
* Since it uses Scripting Bridge, its performance is terribly slow.

Generate The Headers
-----------
```
sdef /Applications/Pages.app | sdp -fh --basename Pages
```