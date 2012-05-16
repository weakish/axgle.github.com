<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/transitional.dtd">
<html>
<head>

  <meta http-equiv="content-type" content="text/html; charset=utf-8">
  <title>Text file src/pkg/runtime/darwin/defs.c</title>

  <link rel="stylesheet" type="text/css" href="../../../../doc/style.css">
  <script type="text/javascript" src="../../../../doc/godocs.js"></script>

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
        <a href="../../../../index.html"><img src="../../../../doc/logo-153x55.png" height="55" width="153" alt="Go Home Page" style="border:0" /></a>
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
    <li class="navhead"><a href="../../../../index.html">Home</a></li>

    <li class="blank">&nbsp;</li>
    <li class="navhead">Documents</li>
    <li><a href="../../../../doc/go_tutorial.html">Tutorial</a></li>
    <li><a href="../../../../doc/effective_go.html">Effective Go</a></li>
    <li><a href="../../../../doc/go_faq.html">FAQ</a></li>
    <li><a href="../../../../doc/go_lang_faq.html">Language Design FAQ</a></li>
    <li><a href="http://www.youtube.com/watch?v=rKnDgT73v8s">Tech talk (1 hour)</a> (<a href="../../../../doc/go_talk-20091030.pdf">PDF</a>)</li>
    <li><a href="../../../../doc/go_spec.html">Language Specification</a></li>
    <li><a href="../../../../doc/go_mem.html">Memory Model</a></li>
    <li><a href="../../../../doc/go_for_cpp_programmers.html">Go for C++ Programmers</a></li>

    <li class="blank">&nbsp;</li>
    <li class="navhead">How To</li>
    <li><a href="../../../../doc/install.html">Install Go</a></li>
    <li><a href="../../../../doc/contribute.html">Contribute code</a></li>

    <li class="blank">&nbsp;</li>
    <li class="navhead">Programming</li>
    <li><a href="../../../../cmd/index.html">Command documentation</a></li>
    <li><a href="../../../../pkg/index.html">Package documentation</a></li>
    <li><a href="../../../index.html">Source files</a></li>

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
	<li>Sun Nov 15 20:28:13 PST 2009</li>
  </ul>
</div>

<div id="content">
  <h1 id="generatedHeader">Text file src/pkg/runtime/darwin/defs.c</h1>

  <!-- The Table of Contents is automatically inserted in this <div>.
       Do not delete this <div>. -->
  <div id="nav"></div>

  <!-- Content is HTML-escaped elsewhere -->
  <pre>
// Copyright 2009 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

/*
 * Input to godefs.
 *
	godefs -f -m64 defs.c &gt;amd64/defs.h
	godefs defs.c &gt;386/defs.h
 */

#define __DARWIN_UNIX03 0

#include &lt;mach/mach.h&gt;
#include &lt;mach/message.h&gt;
#include &lt;sys/types.h&gt;
#include &lt;sys/time.h&gt;
#include &lt;signal.h&gt;
#include &lt;sys/mman.h&gt;

enum {
	$PROT_NONE = PROT_NONE,
	$PROT_READ = PROT_READ,
	$PROT_WRITE = PROT_WRITE,
	$PROT_EXEC = PROT_EXEC,

	$MAP_ANON = MAP_ANON,
	$MAP_PRIVATE = MAP_PRIVATE,

	$MACH_MSG_TYPE_MOVE_RECEIVE = MACH_MSG_TYPE_MOVE_RECEIVE,
	$MACH_MSG_TYPE_MOVE_SEND = MACH_MSG_TYPE_MOVE_SEND,
	$MACH_MSG_TYPE_MOVE_SEND_ONCE = MACH_MSG_TYPE_MOVE_SEND_ONCE,
	$MACH_MSG_TYPE_COPY_SEND = MACH_MSG_TYPE_COPY_SEND,
	$MACH_MSG_TYPE_MAKE_SEND = MACH_MSG_TYPE_MAKE_SEND,
	$MACH_MSG_TYPE_MAKE_SEND_ONCE = MACH_MSG_TYPE_MAKE_SEND_ONCE,
	$MACH_MSG_TYPE_COPY_RECEIVE = MACH_MSG_TYPE_COPY_RECEIVE,

	$MACH_MSG_PORT_DESCRIPTOR = MACH_MSG_PORT_DESCRIPTOR,
	$MACH_MSG_OOL_DESCRIPTOR = MACH_MSG_OOL_DESCRIPTOR,
	$MACH_MSG_OOL_PORTS_DESCRIPTOR = MACH_MSG_OOL_PORTS_DESCRIPTOR,
	$MACH_MSG_OOL_VOLATILE_DESCRIPTOR = MACH_MSG_OOL_VOLATILE_DESCRIPTOR,

	$MACH_MSGH_BITS_COMPLEX = MACH_MSGH_BITS_COMPLEX,

	$MACH_SEND_MSG = MACH_SEND_MSG,
	$MACH_RCV_MSG = MACH_RCV_MSG,
	$MACH_RCV_LARGE = MACH_RCV_LARGE,

	$MACH_SEND_TIMEOUT = MACH_SEND_TIMEOUT,
	$MACH_SEND_INTERRUPT = MACH_SEND_INTERRUPT,
	$MACH_SEND_CANCEL = MACH_SEND_CANCEL,
	$MACH_SEND_ALWAYS = MACH_SEND_ALWAYS,
	$MACH_SEND_TRAILER = MACH_SEND_TRAILER,
	$MACH_RCV_TIMEOUT = MACH_RCV_TIMEOUT,
	$MACH_RCV_NOTIFY = MACH_RCV_NOTIFY,
	$MACH_RCV_INTERRUPT = MACH_RCV_INTERRUPT,
	$MACH_RCV_OVERWRITE = MACH_RCV_OVERWRITE,

	$NDR_PROTOCOL_2_0 = NDR_PROTOCOL_2_0,
	$NDR_INT_BIG_ENDIAN = NDR_INT_BIG_ENDIAN,
	$NDR_INT_LITTLE_ENDIAN = NDR_INT_LITTLE_ENDIAN,
	$NDR_FLOAT_IEEE = NDR_FLOAT_IEEE,
	$NDR_CHAR_ASCII = NDR_CHAR_ASCII,

	$SA_SIGINFO = SA_SIGINFO,
	$SA_RESTART = SA_RESTART,
	$SA_ONSTACK = SA_ONSTACK,
	$SA_USERTRAMP = SA_USERTRAMP,
	$SA_64REGSET = SA_64REGSET,
};

typedef mach_msg_body_t	$MachBody;
typedef mach_msg_header_t	$MachHeader;
typedef NDR_record_t		$MachNDR;
typedef mach_msg_port_descriptor_t	$MachPort;

typedef stack_t	$StackT;
typedef union __sigaction_u	$Sighandler;

typedef struct __sigaction	$Sigaction;	// used in syscalls
// typedef struct sigaction	$Sigaction;	// used by the C library
typedef union sigval $Sigval;
typedef siginfo_t $Siginfo;

typedef struct fp_control $FPControl;
typedef struct fp_status $FPStatus;
typedef struct mmst_reg $RegMMST;
typedef struct xmm_reg $RegXMM;

#ifdef __LP64__
// amd64
typedef x86_thread_state64_t	$Regs;
typedef x86_float_state64_t $FloatState;
typedef x86_exception_state64_t $ExceptionState;
typedef struct mcontext64 $Mcontext;
#else
// 386
typedef x86_thread_state32_t	$Regs;
typedef x86_float_state32_t $FloatState;
typedef x86_exception_state32_t $ExceptionState;
typedef struct mcontext32 $Mcontext;
#endif

typedef ucontext_t	$Ucontext;
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