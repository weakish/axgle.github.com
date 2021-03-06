<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/transitional.dtd">
<html>
<head>

  <meta http-equiv="content-type" content="text/html; charset=utf-8">
  <title>Text file doc/prog.sh</title>

  <link rel="stylesheet" type="text/css" href="style.css">
  <script type="text/javascript" src="godocs.js"></script>

</head>

<body>

  <script>
    // Catch 'enter' key down events and trigger the search form submission.
    function codesearchKeyDown(event) {
      if (event.which == 13) {
        var form = document.getElementById('codesearch');
        var query = document.getElementById('codesearchQuery');
        form.q.value = "lang:go package:go.googlecode.com " + query.value;
        document.getElementById('codesearch').submit();
}      return true;
}
    // Capture the submission event and construct the query parameter.
    function codeSearchSubmit() {
      var query = document.getElementById('codesearchQuery');
      var form = document.getElementById('codesearch');
      form.q.value = "lang:go package:go.googlecode.com " + query.value;
      return true;
}  </script>

<div id="topnav">
  <table summary="">
    <tr>
      <td id="headerImage">
        <a href="../index.html"><img src="logo-153x55.png" height="55" width="153" alt="Go Home Page" style="border:0" /></a>
      </td>
      <td>
        <div id="headerDocSetTitle">The Go Programming Language</div>
      </td>
      <td>
        <!-- <table>
          <tr>
            <td>
              <! The input box is outside of the form because we want to add
              a couple of restricts to the query before submitting. If we just
              add the restricts to the text box before submitting, then they
              appear in the box when the user presses 'back'. Thus we use a
              hidden field in the form. However, there's no way to stop the
              non-hidden text box from also submitting a value unless we move
              it outside of the form
              <input type="search" id="codesearchQuery" value="" size="30" onkeydown="return codesearchKeyDown(event);"/>
              <form method="GET" action="http://www.google.com/codesearch" id="codesearch" class="search" onsubmit="return codeSearchSubmit();" style="display:inline;">
                <input type="hidden" name="q" value=""/>
                <input type="submit" value="Code search" />
                <span style="color: red">(TODO: remove for now?)</span>
              </form>
            </td>
          </tr>
          <tr>
            <td>
              <span style="color: gray;">(e.g. &ldquo;pem&rdquo; or &ldquo;xml&rdquo;)</span>
            </td>
          </tr>
        </table> -->
      </td>
    </tr>
  </table>
</div>

<div id="linkList">
  <ul>
    <li class="navhead"><a href="../index.html">Home</a></li>

    <li class="blank">&nbsp;</li>
    <li class="navhead">Documents</li>
    <li><a href="go_tutorial.html">Tutorial</a></li>
    <li><a href="effective_go.html">Effective Go</a></li>
    <li><a href="go_faq.html">FAQ</a></li>
    <li><a href="go_lang_faq.html">Language Design FAQ</a></li>
    <li><a href="http://www.youtube.com/watch?v=rKnDgT73v8s">Tech talk (1 hour)</a> (<a href="go_talk-20091030.pdf">PDF</a>)</li>
    <li><a href="go_spec.html">Language Specification</a></li>
    <li><a href="go_mem.html">Memory Model</a></li>
    <li><a href="go_for_cpp_programmers.html">Go for C++ Programmers</a></li>

    <li class="blank">&nbsp;</li>
    <li class="navhead">How To</li>
    <li><a href="install.html">Install Go</a></li>
    <li><a href="contribute.html">Contribute code</a></li>

    <li class="blank">&nbsp;</li>
    <li class="navhead">Programming</li>
    <li><a href="../cmd/index.html">Command documentation</a></li>
    <li><a href="../pkg/index.html">Package documentation</a></li>
    <li><a href="../src/index.html">Source files</a></li>

    <li class="blank">&nbsp;</li>
    <li class="navhead">Help</li>
    <li>#go-nuts on irc.freenode.net</li>
    <li><a href="http://groups.google.com/group/golang-nuts">Go Nuts mailing list</a></li>
    <li><a href="http://code.google.com/p/go/issues/list">Issue tracker</a></li>

    <li class="blank">&nbsp;</li>
    <li class="navhead">Go code search</li>
    <form method="GET" action="http://golang.org/search" class="search">
    <input type="search" name="q" value="" size="25" style="width:80%; max-width:200px" />
    <input type="submit" value="Go" />
    </form>

    <li class="blank">&nbsp;</li>
    <li class="navhead">Last update</li>
	<li>Thu Nov 12 15:49:51 PST 2009</li>
  </ul>
</div>

<div id="content">
  <h1 id="generatedHeader">Text file doc/prog.sh</h1>

  <!-- The Table of Contents is automatically inserted in this <div>.
       Do not delete this <div>. -->
  <div id="nav"></div>

  <!-- Content is HTML-escaped elsewhere -->
  <pre>
#!/bin/sh
# Copyright 2009 The Go Authors. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

# generate HTML for a program excerpt.
# first arg is file name
# second arg is awk pattern to match start line
# third arg is awk pattern to stop processing
#
# missing third arg means print one line
# third arg &#34;END&#34; means proces rest of file
# missing second arg means process whole file
#
# examples:
#
#	prog.sh foo.go                       # whole file
#	prog.sh foo.go &#34;/^func.main/&#34;        # signature of main
#	prog.sh foo.go &#34;/^func.main/&#34; &#34;/^}/  # body of main
#
# non-blank lines are annotated with line number in file

# line numbers are printed %.2d to make them equal-width for nice formatting.
# the format gives a leading 0.  the format %2d gives a leading space but
# that appears to confuse sanjay&#39;s makehtml formatter into bungling quotes
# because it makes some lines look indented.

echo &#34;&lt;pre&gt; &lt;!-- $* --&gt;&#34;

case $# in
3)
	if test &#34;$3&#34; = &#34;END&#34;  # $2 to end of file
	then
		awk &#39;
			function LINE() { printf(&#34;%.2d\t%s\n&#34;, NR, $0) }
			BEGIN { printing = 0 }
			&#39;$2&#39; { printing = 1; LINE(); getline }
			printing { if($0 ~ /./) { LINE() } else { print &#34;&#34; } }
		&#39;
	else	# $2 through $3
		awk &#39;
			function LINE() { printf(&#34;%.2d\t%s\n&#34;, NR, $0) }
			BEGIN { printing = 0 }
			&#39;$2&#39; { printing = 1; LINE(); getline }
			&#39;$3&#39; &amp;&amp; printing { if(printing) {printing = 0; LINE(); exit} }
			printing { if($0 ~ /./) { LINE() } else { print &#34;&#34; } }
		&#39;
	fi
	;;
2)	# one line
	awk &#39;
		function LINE() { printf(&#34;%.2d\t%s\n&#34;, NR, $0) }
		&#39;$2&#39; { LINE(); getline; exit }
	&#39;
	;;
1)	# whole file
	awk &#39;
		function LINE() { printf(&#34;%.2d\t%s\n&#34;, NR, $0) }
		{ if($0 ~ /./) { LINE() } else { print &#34;&#34; } }
	&#39;
	;;
*)
	echo &gt;&amp;2 usage: prog.sh file.go /func.main/ /^}/
esac &lt;$1 |
sed &#39;
	s/&amp;/\&amp;amp;/g
	s/&#34;/\&amp;quot;/g
	s/&lt;/\&amp;lt;/g
	s/&gt;/\&amp;gt;/g
&#39;

echo &#39;&lt;/pre&gt;&#39;
</pre>

</div>

<div id="footer">
<p>Except as noted, this content is
   licensed under <a href="http://creativecommons.org/licenses/by/3.0/">
   Creative Commons Attribution 3.0</a>.
</div>

<script type="text/javascript">
var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
</script>
<script type="text/javascript">
var pageTracker = _gat._getTracker("UA-11222381-2");
pageTracker._trackPageview();
</script>
</body>
</html>
<!-- generated at Thu Nov 12 15:42:51 PST 2009 -->
