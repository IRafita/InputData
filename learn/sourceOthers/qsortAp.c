<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en"><head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
<title>qsort.c</title>
<style type="text/css">
.enscript-comment { font-style: italic; color: rgb(178,34,34); }
.enscript-function-name { font-weight: bold; color: rgb(0,0,255); }
.enscript-variable-name { font-weight: bold; color: rgb(184,134,11); }
.enscript-keyword { font-weight: bold; color: rgb(160,32,240); }
.enscript-reference { font-weight: bold; color: rgb(95,158,160); }
.enscript-string { font-weight: bold; color: rgb(188,143,143); }
.enscript-builtin { font-weight: bold; color: rgb(218,112,214); }
.enscript-type { font-weight: bold; color: rgb(34,139,34); }
.enscript-highlight { text-decoration: underline; color: 0; }
</style>
</head>
<body id="top">
<h1 style="margin:8px;" id="f1">qsort.c&nbsp;&nbsp;&nbsp;<span style="font-weight: normal; font-size: 0.5em;">[<a href="http://www.opensource.apple.com/source/xnu/xnu-1456.1.26/bsd/kern/qsort.c?txt">plain text</a>]</span></h1>
<hr>
<div></div>
<pre><span class="enscript-comment">/*
 * Copyright (c) 2000-2006 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 * 
 * Please obtain a copy of the License at
 * <a href="http://www.opensource.apple.com/apsl/">http://www.opensource.apple.com/apsl/</a> and read it before using this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */</span>
<span class="enscript-comment">/*
 * Copyright (c) 1995 NeXT Computer, Inc. All Rights Reserved
 *
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)qsort.c	8.1 (Berkeley) 6/4/93
 */</span>


#<span class="enscript-reference">include</span> <span class="enscript-string">&lt;sys/types.h&gt;</span>
<span class="enscript-comment">//#include &lt;stdlib.h&gt;
</span>
__private_extern__
<span class="enscript-type">void</span>
<span class="enscript-function-name">qsort</span>(<span class="enscript-type">void</span> *a, size_t n, size_t es, <span class="enscript-type">int</span> (*cmp)(<span class="enscript-type">const</span> <span class="enscript-type">void</span> *, <span class="enscript-type">const</span> <span class="enscript-type">void</span> *));

<span class="enscript-type">static</span> inline <span class="enscript-type">char</span>	*med3(<span class="enscript-type">char</span> *, <span class="enscript-type">char</span> *, <span class="enscript-type">char</span> *, <span class="enscript-type">int</span> (*)(<span class="enscript-type">const</span> <span class="enscript-type">void</span> *, <span class="enscript-type">const</span> <span class="enscript-type">void</span> *));
<span class="enscript-type">static</span> inline <span class="enscript-type">void</span>	 swapfunc(<span class="enscript-type">char</span> *, <span class="enscript-type">char</span> *, <span class="enscript-type">int</span>, <span class="enscript-type">int</span>);

#<span class="enscript-reference">define</span> <span class="enscript-function-name">min</span>(a, b)	(a) &lt; (b) ? a : b

<span class="enscript-comment">/*
 * Qsort routine from Bentley &amp; McIlroy's "Engineering a Sort Function".
 */</span>
#<span class="enscript-reference">define</span> <span class="enscript-function-name">swapcode</span>(TYPE, parmi, parmj, n) { 		\
	<span class="enscript-type">long</span> i = (n) / <span class="enscript-keyword">sizeof</span> (TYPE); 			\
	TYPE *pi = (TYPE *) (parmi); 			\
	TYPE *pj = (TYPE *) (parmj); 			\
	<span class="enscript-keyword">do</span> { 						\
		TYPE	t = *pi;			\
		*pi++ = *pj;				\
		*pj++ = t;				\
        } <span class="enscript-keyword">while</span> (--i &gt; 0);				\
}

#<span class="enscript-reference">define</span> <span class="enscript-function-name">SWAPINIT</span>(a, es) swaptype = ((char *)a - (char *)0) % sizeof(long) || \
	es % <span class="enscript-keyword">sizeof</span>(<span class="enscript-type">long</span>) ? 2 : es == <span class="enscript-keyword">sizeof</span>(<span class="enscript-type">long</span>)? 0 : 1;

<span class="enscript-type">static</span> inline <span class="enscript-type">void</span>
<span class="enscript-function-name">swapfunc</span>(<span class="enscript-type">char</span> *a, <span class="enscript-type">char</span> *b, <span class="enscript-type">int</span> n, <span class="enscript-type">int</span> swaptype)
{
	<span class="enscript-keyword">if</span>(swaptype &lt;= 1) 
		swapcode(<span class="enscript-type">long</span>, a, b, n)
	<span class="enscript-keyword">else</span>
		swapcode(<span class="enscript-type">char</span>, a, b, n)
}

#<span class="enscript-reference">define</span> <span class="enscript-function-name">swap</span>(a, b)					\
	<span class="enscript-keyword">if</span> (swaptype == 0) {				\
		<span class="enscript-type">long</span> t = *(<span class="enscript-type">long</span> *)(a);			\
		*(<span class="enscript-type">long</span> *)(a) = *(<span class="enscript-type">long</span> *)(b);		\
		*(<span class="enscript-type">long</span> *)(b) = t;			\
	} <span class="enscript-keyword">else</span>						\
		swapfunc(a, b, es, swaptype)

#<span class="enscript-reference">define</span> <span class="enscript-function-name">vecswap</span>(a, b, n) 	if ((n) &gt; 0) swapfunc(a, b, n, swaptype)

<span class="enscript-type">static</span> inline <span class="enscript-type">char</span> *
<span class="enscript-function-name">med3</span>(<span class="enscript-type">char</span> *a, <span class="enscript-type">char</span> *b, <span class="enscript-type">char</span> *c, <span class="enscript-type">int</span> (*cmp)(<span class="enscript-type">const</span> <span class="enscript-type">void</span> *, <span class="enscript-type">const</span> <span class="enscript-type">void</span> *))
{
	<span class="enscript-keyword">return</span> cmp(a, b) &lt; 0 ?
	       (cmp(b, c) &lt; 0 ? b : (cmp(a, c) &lt; 0 ? c : a ))
              :(cmp(b, c) &gt; 0 ? b : (cmp(a, c) &lt; 0 ? a : c ));
}

__private_extern__
<span class="enscript-type">void</span>
<span class="enscript-function-name">qsort</span>(<span class="enscript-type">void</span> *a, size_t n, size_t es, <span class="enscript-type">int</span> (*cmp)(<span class="enscript-type">const</span> <span class="enscript-type">void</span> *, <span class="enscript-type">const</span> <span class="enscript-type">void</span> *))
{
	<span class="enscript-type">char</span> *pa, *pb, *pc, *pd, *pl, *pm, *pn;
	<span class="enscript-type">int</span> d, swaptype, swap_cnt;
	<span class="enscript-type">int</span> r;

<span class="enscript-reference">loop</span>:	SWAPINIT(a, es);
	swap_cnt = 0;
	<span class="enscript-keyword">if</span> (n &lt; 7) {
		<span class="enscript-keyword">for</span> (pm = (<span class="enscript-type">char</span> *)a + es; pm &lt; (<span class="enscript-type">char</span> *) a + n * es; pm += es)
			<span class="enscript-keyword">for</span> (pl = pm; pl &gt; (<span class="enscript-type">char</span> *) a &amp;&amp; cmp(pl - es, pl) &gt; 0;
			     pl -= es)
				swap(pl, pl - es);
		<span class="enscript-keyword">return</span>;
	}
	pm = (<span class="enscript-type">char</span> *)a + (n / 2) * es;
	<span class="enscript-keyword">if</span> (n &gt; 7) {
		pl = a;
		pn = (<span class="enscript-type">char</span> *)a + (n - 1) * es;
		<span class="enscript-keyword">if</span> (n &gt; 40) {
			d = (n / 8) * es;
			pl = med3(pl, pl + d, pl + 2 * d, cmp);
			pm = med3(pm - d, pm, pm + d, cmp);
			pn = med3(pn - 2 * d, pn - d, pn, cmp);
		}
		pm = med3(pl, pm, pn, cmp);
	}
	swap(a, pm);
	pa = pb = (<span class="enscript-type">char</span> *)a + es;

	pc = pd = (<span class="enscript-type">char</span> *)a + (n - 1) * es;
	<span class="enscript-keyword">for</span> (;;) {
		<span class="enscript-keyword">while</span> (pb &lt;= pc &amp;&amp; (r = cmp(pb, a)) &lt;= 0) {
			<span class="enscript-keyword">if</span> (r == 0) {
				swap_cnt = 1;
				swap(pa, pb);
				pa += es;
			}
			pb += es;
		}
		<span class="enscript-keyword">while</span> (pb &lt;= pc &amp;&amp; (r = cmp(pc, a)) &gt;= 0) {
			<span class="enscript-keyword">if</span> (r == 0) {
				swap_cnt = 1;
				swap(pc, pd);
				pd -= es;
			}
			pc -= es;
		}
		<span class="enscript-keyword">if</span> (pb &gt; pc)
			<span class="enscript-keyword">break</span>;
		swap(pb, pc);
		swap_cnt = 1;
		pb += es;
		pc -= es;
	}
	<span class="enscript-keyword">if</span> (swap_cnt == 0) {  <span class="enscript-comment">/* Switch to insertion sort */</span>
		<span class="enscript-keyword">for</span> (pm = (<span class="enscript-type">char</span> *)a + es; pm &lt; (<span class="enscript-type">char</span> *) a + n * es; pm += es)
			<span class="enscript-keyword">for</span> (pl = pm; pl &gt; (<span class="enscript-type">char</span> *) a &amp;&amp; cmp(pl - es, pl) &gt; 0; 
			     pl -= es)
				swap(pl, pl - es);
		<span class="enscript-keyword">return</span>;
	}

	pn = (<span class="enscript-type">char</span> *)a + n * es;
	r = min(pa - (<span class="enscript-type">char</span> *)a, pb - pa);
	vecswap(a, pb - r, r);
	r = min((size_t)(pd - pc), pn - pd - es);
	vecswap(pb, pn - r, r);
	<span class="enscript-keyword">if</span> ((size_t)(r = pb - pa) &gt; es)
		qsort(a, r / es, es, cmp);
	<span class="enscript-keyword">if</span> ((size_t)(r = pd - pc) &gt; es) { 
		<span class="enscript-comment">/* Iterate rather than recurse to save stack space */</span>
		a = pn - r;
		n = r / es;
		<span class="enscript-keyword">goto</span> <span class="enscript-reference">loop</span>;
	}
<span class="enscript-comment">/*		qsort(pn - r, r / es, es, cmp);*/</span>
}
</pre>
<hr>
</body></html>