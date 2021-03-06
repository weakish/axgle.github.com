<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/transitional.dtd">
<html>
<head>

  <meta http-equiv="content-type" content="text/html; charset=utf-8">
  <title>Text file src/lib9/fmt/test.c</title>

  <link rel="stylesheet" type="text/css" href="../../../doc/style.css">
  <script type="text/javascript" src="../../../doc/godocs.js"></script>

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
        <a href="../../../index.html"><img src="../../../doc/logo-153x55.png" height="55" width="153" alt="Go Home Page" style="border:0" /></a>
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
    <li class="navhead"><a href="../../../index.html">Home</a></li>

    <li class="blank">&nbsp;</li>
    <li class="navhead">Documents</li>
    <li><a href="../../../doc/go_tutorial.html">Tutorial</a></li>
    <li><a href="../../../doc/effective_go.html">Effective Go</a></li>
    <li><a href="../../../doc/go_faq.html">FAQ</a></li>
    <li><a href="../../../doc/go_lang_faq.html">Language Design FAQ</a></li>
    <li><a href="http://www.youtube.com/watch?v=rKnDgT73v8s">Tech talk (1 hour)</a> (<a href="../../../doc/go_talk-20091030.pdf">PDF</a>)</li>
    <li><a href="../../../doc/go_spec.html">Language Specification</a></li>
    <li><a href="../../../doc/go_mem.html">Memory Model</a></li>
    <li><a href="../../../doc/go_for_cpp_programmers.html">Go for C++ Programmers</a></li>

    <li class="blank">&nbsp;</li>
    <li class="navhead">How To</li>
    <li><a href="../../../doc/install.html">Install Go</a></li>
    <li><a href="../../../doc/contribute.html">Contribute code</a></li>

    <li class="blank">&nbsp;</li>
    <li class="navhead">Programming</li>
    <li><a href="../../../cmd/index.html">Command documentation</a></li>
    <li><a href="../../../pkg/index.html">Package documentation</a></li>
    <li><a href="../../index.html">Source files</a></li>

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
	<li>Thu Nov 12 15:47:43 PST 2009</li>
  </ul>
</div>

<div id="content">
  <h1 id="generatedHeader">Text file src/lib9/fmt/test.c</h1>

  <!-- The Table of Contents is automatically inserted in this <div>.
       Do not delete this <div>. -->
  <div id="nav"></div>

  <!-- Content is HTML-escaped elsewhere -->
  <pre>
/*
 * The authors of this software are Rob Pike and Ken Thompson,
 * with contributions from Mike Burrows and Sean Dorward.
 *
 *     Copyright (c) 2002-2006 by Lucent Technologies.
 *     Portions Copyright (c) 2004 Google Inc.
 * 
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 * THIS SOFTWARE IS BEING PROVIDED &#34;AS IS&#34;, WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHORS NOR LUCENT TECHNOLOGIES 
 * NOR GOOGLE INC MAKE ANY REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING 
 * THE MERCHANTABILITY OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 */

#include &lt;u.h&gt;
#include &lt;libc.h&gt;
#include &#34;fmtdef.h&#34;

int
main(int argc, char *argv[])
{
	quotefmtinstall();
	print(&#34;hello world\n&#34;);
	print(&#34;x: %x\n&#34;, 0x87654321);
	print(&#34;u: %u\n&#34;, 0x87654321);
	print(&#34;d: %d\n&#34;, 0x87654321);
	print(&#34;s: %s\n&#34;, &#34;hi there&#34;);
	print(&#34;q: %q\n&#34;, &#34;hi i&#39;m here&#34;);
	print(&#34;c: %c\n&#34;, &#39;!&#39;);
	print(&#34;g: %g %g %g\n&#34;, 3.14159, 3.14159e10, 3.14159e-10);
	print(&#34;e: %e %e %e\n&#34;, 3.14159, 3.14159e10, 3.14159e-10);
	print(&#34;f: %f %f %f\n&#34;, 3.14159, 3.14159e10, 3.14159e-10);
	print(&#34;smiley: %C\n&#34;, (Rune)0x263a);
	print(&#34;%g %.18g\n&#34;, 2e25, 2e25);
	print(&#34;%2.18g\n&#34;, 1.0);
	print(&#34;%2.18f\n&#34;, 1.0);
	print(&#34;%f\n&#34;, 3.1415927/4);
	print(&#34;%d\n&#34;, 23);
	print(&#34;%i\n&#34;, 23);
	print(&#34;%0.10d\n&#34;, 12345);

	/* test %4$d formats */
	print(&#34;%3$d %4$06d %2$d %1$d\n&#34;, 444, 333, 111, 222);
	print(&#34;%3$d %4$06d %2$d %1$d\n&#34;, 444, 333, 111, 222);
	print(&#34;%3$d %4$*5$06d %2$d %1$d\n&#34;, 444, 333, 111, 222, 20);
	print(&#34;%3$hd %4$*5$06d %2$d %1$d\n&#34;, 444, 333, (short)111, 222, 20);
	print(&#34;%3$lld %4$*5$06d %2$d %1$d\n&#34;, 444, 333, 111LL, 222, 20);

	/* test %&#39;d formats */
	print(&#34;%&#39;d %&#39;d %&#39;d\n&#34;, 1, 2222, 33333333);
	print(&#34;%&#39;019d\n&#34;, 0);
	print(&#34;%08d %08d %08d\n&#34;, 1, 2222, 33333333);
	print(&#34;%&#39;08d %&#39;08d %&#39;08d\n&#34;, 1, 2222, 33333333);
	print(&#34;%&#39;x %&#39;X %&#39;b\n&#34;, 0x11111111, 0xabcd1234, 12345);
	print(&#34;%&#39;lld %&#39;lld %&#39;lld\n&#34;, 1LL, 222222222LL, 3333333333333LL);
	print(&#34;%019lld %019lld %019lld\n&#34;, 1LL, 222222222LL, 3333333333333LL);
	print(&#34;%&#39;019lld %&#39;019lld %&#39;019lld\n&#34;, 1LL, 222222222LL, 3333333333333LL);
	print(&#34;%&#39;020lld %&#39;020lld %&#39;020lld\n&#34;, 1LL, 222222222LL, 3333333333333LL);
	print(&#34;%&#39;llx %&#39;llX %&#39;llb\n&#34;, 0x111111111111LL, 0xabcd12345678LL, 112342345LL);
	return 0;
}
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
