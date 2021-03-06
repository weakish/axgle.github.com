<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/transitional.dtd">
<html>
<head>

  <meta http-equiv="content-type" content="text/html; charset=utf-8">
  <title>Source file /src/pkg/flag/flag_test.go</title>

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
	<li>Thu Nov 12 15:47:27 PST 2009</li>
  </ul>
</div>

<div id="content">
  <h1 id="generatedHeader">Source file /src/pkg/flag/flag_test.go</h1>

  <!-- The Table of Contents is automatically inserted in this <div>.
       Do not delete this <div>. -->
  <div id="nav"></div>

  <!-- Content is HTML-escaped elsewhere -->
  <pre>
<a id="L1"></a><span class="comment">// Copyright 2009 The Go Authors. All rights reserved.</span>
<a id="L2"></a><span class="comment">// Use of this source code is governed by a BSD-style</span>
<a id="L3"></a><span class="comment">// license that can be found in the LICENSE file.</span>

<a id="L5"></a>package flag_test

<a id="L7"></a>import (
    <a id="L8"></a>. &#34;flag&#34;;
    <a id="L9"></a>&#34;testing&#34;;
<a id="L10"></a>)

<a id="L12"></a>var (
    <a id="L13"></a>test_bool    = Bool(&#34;test_bool&#34;, false, &#34;bool value&#34;);
    <a id="L14"></a>test_int     = Int(&#34;test_int&#34;, 0, &#34;int value&#34;);
    <a id="L15"></a>test_int64   = Int64(&#34;test_int64&#34;, 0, &#34;int64 value&#34;);
    <a id="L16"></a>test_uint    = Uint(&#34;test_uint&#34;, 0, &#34;uint value&#34;);
    <a id="L17"></a>test_uint64  = Uint64(&#34;test_uint64&#34;, 0, &#34;uint64 value&#34;);
    <a id="L18"></a>test_string  = String(&#34;test_string&#34;, &#34;0&#34;, &#34;string value&#34;);
    <a id="L19"></a>test_float   = Float(&#34;test_float&#34;, 0, &#34;float value&#34;);
    <a id="L20"></a>test_float64 = Float(&#34;test_float64&#34;, 0, &#34;float64 value&#34;);
<a id="L21"></a>)

<a id="L23"></a>func boolString(s string) string {
    <a id="L24"></a>if s == &#34;0&#34; {
        <a id="L25"></a>return &#34;false&#34;
    <a id="L26"></a>}
    <a id="L27"></a>return &#34;true&#34;;
<a id="L28"></a>}

<a id="L30"></a>func TestEverything(t *testing.T) {
    <a id="L31"></a>m := make(map[string]*Flag);
    <a id="L32"></a>desired := &#34;0&#34;;
    <a id="L33"></a>visitor := func(f *Flag) {
        <a id="L34"></a>if len(f.Name) &gt; 5 &amp;&amp; f.Name[0:5] == &#34;test_&#34; {
            <a id="L35"></a>m[f.Name] = f;
            <a id="L36"></a>ok := false;
            <a id="L37"></a>switch {
            <a id="L38"></a>case f.Value.String() == desired:
                <a id="L39"></a>ok = true
            <a id="L40"></a>case f.Name == &#34;test_bool&#34; &amp;&amp; f.Value.String() == boolString(desired):
                <a id="L41"></a>ok = true
            <a id="L42"></a>}
            <a id="L43"></a>if !ok {
                <a id="L44"></a>t.Error(&#34;Visit: bad value&#34;, f.Value.String(), &#34;for&#34;, f.Name)
            <a id="L45"></a>}
        <a id="L46"></a>}
    <a id="L47"></a>};
    <a id="L48"></a>VisitAll(visitor);
    <a id="L49"></a>if len(m) != 8 {
        <a id="L50"></a>t.Error(&#34;VisitAll misses some flags&#34;);
        <a id="L51"></a>for k, v := range m {
            <a id="L52"></a>t.Log(k, *v)
        <a id="L53"></a>}
    <a id="L54"></a>}
    <a id="L55"></a>m = make(map[string]*Flag);
    <a id="L56"></a>Visit(visitor);
    <a id="L57"></a>if len(m) != 0 {
        <a id="L58"></a>t.Errorf(&#34;Visit sees unset flags&#34;);
        <a id="L59"></a>for k, v := range m {
            <a id="L60"></a>t.Log(k, *v)
        <a id="L61"></a>}
    <a id="L62"></a>}
    <a id="L63"></a><span class="comment">// Now set all flags</span>
    <a id="L64"></a>Set(&#34;test_bool&#34;, &#34;true&#34;);
    <a id="L65"></a>Set(&#34;test_int&#34;, &#34;1&#34;);
    <a id="L66"></a>Set(&#34;test_int64&#34;, &#34;1&#34;);
    <a id="L67"></a>Set(&#34;test_uint&#34;, &#34;1&#34;);
    <a id="L68"></a>Set(&#34;test_uint64&#34;, &#34;1&#34;);
    <a id="L69"></a>Set(&#34;test_string&#34;, &#34;1&#34;);
    <a id="L70"></a>Set(&#34;test_float&#34;, &#34;1&#34;);
    <a id="L71"></a>Set(&#34;test_float64&#34;, &#34;1&#34;);
    <a id="L72"></a>desired = &#34;1&#34;;
    <a id="L73"></a>Visit(visitor);
    <a id="L74"></a>if len(m) != 8 {
        <a id="L75"></a>t.Error(&#34;Visit fails after set&#34;);
        <a id="L76"></a>for k, v := range m {
            <a id="L77"></a>t.Log(k, *v)
        <a id="L78"></a>}
    <a id="L79"></a>}
<a id="L80"></a>}
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
