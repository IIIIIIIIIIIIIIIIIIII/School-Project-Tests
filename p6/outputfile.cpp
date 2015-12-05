<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Source Code</title>
<style type="text/css">
<!--
pre { white-space: pre-wrap; font-family: monospace; color: #839496; background-color: #002b36; }
body { font-family: monospace; color: #839496; background-color: #002b36; }
.statement { color: #719e07; font-weight: bold; }
.comment { color: #586e75; font-style: italic; }
.strlit { color: #2aa198; }
.preproc { color: #cb4b16; font-weight: bold; }
.type { color: #b58900; }
.numeric { color: #6c71c4; }
.escseq { color: #dc322f; }
.error { color: #dc322f; font-weight: bold; font-size: larger}
-->
</style>
</head>
<body>
<pre>
<span class='preproc'>#include</span> <span class='strlit'>"</span><span class='strlit'>f</span><span class='strlit'>s</span><span class='strlit'>m</span><span class='strlit'>.</span><span class='strlit'>h</span><span class='strlit'>"</span>
<span class='statement'>using</span> <span class='statement'>namespace</span> cppfsm;
<span class='preproc'>#include</span> &lt;vector&gt;
<span class='statement'>using</span> std::vector;
<span class='preproc'>#include</span> &lt;iostream&gt;
<span class='statement'>using</span> std::cin;
<span class='statement'>using</span> std::cout;
<span class='statement'>using</span> std::endl;

<span class='type'>int</span> cppfsm::updateState(<span class='type'>int</span>&amp; state, <span class='type'>char</span> c) {
&nbsp;&nbsp;&nbsp;&nbsp;<span class='type'>int</span> oldstate = state;

&nbsp;&nbsp;&nbsp;&nbsp;<span class='comment'>/</span><span class='comment'>/</span><span class='comment'> </span><span class='comment'>f</span><span class='comment'>o</span><span class='comment'>r</span><span class='comment'> </span><span class='comment'>o</span><span class='comment'>u</span><span class='comment'>r</span><span class='comment'> </span><span class='comment'>s</span><span class='comment'>i</span><span class='comment'>m</span><span class='comment'>p</span><span class='comment'>l</span><span class='comment'>i</span><span class='comment'>f</span><span class='comment'>i</span><span class='comment'>e</span><span class='comment'>d</span><span class='comment'> </span><span class='comment'>s</span><span class='comment'>y</span><span class='comment'>n</span><span class='comment'>t</span><span class='comment'>a</span><span class='comment'>x</span><span class='comment'>,</span><span class='comment'> </span><span class='comment'>w</span><span class='comment'>e</span><span class='comment'> </span><span class='comment'>a</span><span class='comment'>l</span><span class='comment'>w</span><span class='comment'>a</span><span class='comment'>y</span><span class='comment'>s</span><span class='comment'> </span><span class='comment'>r</span><span class='comment'>e</span><span class='comment'>t</span><span class='comment'>u</span><span class='comment'>r</span><span class='comment'>n</span><span class='comment'> </span><span class='comment'>t</span><span class='comment'>o</span><span class='comment'> </span><span class='comment'>t</span><span class='comment'>h</span><span class='comment'>e</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class='comment'>/</span><span class='comment'>/</span><span class='comment'> </span><span class='comment'>s</span><span class='comment'>t</span><span class='comment'>a</span><span class='comment'>r</span><span class='comment'>t</span><span class='comment'> </span><span class='comment'>s</span><span class='comment'>t</span><span class='comment'>a</span><span class='comment'>t</span><span class='comment'>e</span><span class='comment'> </span><span class='comment'>o</span><span class='comment'>n</span><span class='comment'> </span><span class='comment'>a</span><span class='comment'> </span><span class='comment'>n</span><span class='comment'>e</span><span class='comment'>w</span><span class='comment'> </span><span class='comment'>l</span><span class='comment'>i</span><span class='comment'>n</span><span class='comment'>e</span><span class='comment'>:</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>if</span> (c == &apos;\n') {
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = start;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>return</span> oldstate;
&nbsp;&nbsp;&nbsp;&nbsp;}

&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>switch</span> (state) {
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>case</span> start:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>if</span> (INSET(c,num))
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = scannum;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (INSET(c,ident_st))
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = scanid;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (c == &apos;<span class='strlit'>"</span><span class='strlit'>'</span><span class='strlit'>)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = strlit;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (c == &apos;<span class='comment'>/</span><span class='comment'>'</span><span class='comment'>)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = readfs;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>break</span>;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>case</span> scanid:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>if</span> (INSET(c,iddelim))
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = start;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (c == &apos;<span class='comment'>/</span><span class='comment'>'</span><span class='comment'>)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = readfs;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (c == &apos;<span class='strlit'>"</span><span class='strlit'>'</span><span class='strlit'>)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = strlit;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>break</span>;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>case</span> scannum:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>if</span> (INSET(c,iddelim))
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = start; 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (INSET(c,num))
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = scannum; <span class='comment'>/</span><span class='comment'>/</span><span class='comment'> </span><span class='comment'>d</span><span class='comment'>o</span><span class='comment'>n</span><span class='comment'>'</span><span class='comment'>t</span><span class='comment'> </span><span class='comment'>c</span><span class='comment'>h</span><span class='comment'>a</span><span class='comment'>n</span><span class='comment'>g</span><span class='comment'>e</span><span class='comment'> </span><span class='comment'>s</span><span class='comment'>t</span><span class='comment'>a</span><span class='comment'>t</span><span class='comment'>e</span><span class='comment'>.</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (c == &apos;<span class='comment'>/</span><span class='comment'>'</span><span class='comment'>)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    state = readfs;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (c == &apos;<span class='strlit'>"</span><span class='strlit'>'</span><span class='strlit'>)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = strlit;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<span class='statement'>else</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = error;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>break</span>;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>case</span> readfs:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>if</span> (INSET(c,ident_st))
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = scanid;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (INSET(c,num))
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = scannum; 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (c == &apos;<span class='comment'>/</span><span class='comment'>'</span><span class='comment'>)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = comment;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (c == &apos;<span class='strlit'>"</span><span class='strlit'>'</span><span class='strlit'>)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = strlit;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>break</span>;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>case</span> comment:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>break</span>;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>case</span> strlit:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>if</span> (c == &apos;\\&apos;)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = readesc;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>else</span> <span class='statement'>if</span> (c == &apos;<span class='strlit'>"</span><span class='strlit'>'</span><span class='strlit'>)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = start;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>break</span>;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>case</span> readesc:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>if</span> (INSET(c,escseq))
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = strlit;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<span class='statement'>else</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;state = error;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>break</span>;

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>default</span>:  <span class='comment'>/</span><span class='comment'>/</span><span class='comment'> </span><span class='comment'>t</span><span class='comment'>h</span><span class='comment'>i</span><span class='comment'>s</span><span class='comment'> </span><span class='comment'>i</span><span class='comment'>s</span><span class='comment'> </span><span class='comment'>t</span><span class='comment'>h</span><span class='comment'>e</span><span class='comment'> </span><span class='comment'>e</span><span class='comment'>r</span><span class='comment'>r</span><span class='comment'>o</span><span class='comment'>r</span><span class='comment'> </span><span class='comment'>s</span><span class='comment'>t</span><span class='comment'>a</span><span class='comment'>t</span><span class='comment'>e</span><span class='comment'>.</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='comment'>/</span><span class='comment'>/</span><span class='comment'> </span><span class='comment'>F</span><span class='comment'>o</span><span class='comment'>r</span><span class='comment'> </span><span class='comment'>n</span><span class='comment'>o</span><span class='comment'>w</span><span class='comment'>,</span><span class='comment'> </span><span class='comment'>w</span><span class='comment'>e</span><span class='comment'>'</span><span class='comment'>l</span><span class='comment'>l</span><span class='comment'> </span><span class='comment'>j</span><span class='comment'>u</span><span class='comment'>s</span><span class='comment'>t</span><span class='comment'> </span><span class='comment'>s</span><span class='comment'>t</span><span class='comment'>a</span><span class='comment'>y</span><span class='comment'> </span><span class='comment'>i</span><span class='comment'>n</span><span class='comment'> </span><span class='comment'>t</span><span class='comment'>h</span><span class='comment'>e</span><span class='comment'> </span><span class='comment'>e</span><span class='comment'>r</span><span class='comment'>r</span><span class='comment'>o</span><span class='comment'>r</span><span class='comment'> </span><span class='comment'>s</span><span class='comment'>t</span><span class='comment'>a</span><span class='comment'>t</span><span class='comment'>e</span><span class='comment'> </span><span class='comment'>u</span><span class='comment'>n</span><span class='comment'>t</span><span class='comment'>i</span><span class='comment'>l</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='comment'>/</span><span class='comment'>/</span><span class='comment'> </span><span class='comment'>t</span><span class='comment'>h</span><span class='comment'>e</span><span class='comment'> </span><span class='comment'>e</span><span class='comment'>n</span><span class='comment'>d</span><span class='comment'> </span><span class='comment'>o</span><span class='comment'>f</span><span class='comment'> </span><span class='comment'>t</span><span class='comment'>h</span><span class='comment'>e</span><span class='comment'> </span><span class='comment'>l</span><span class='comment'>i</span><span class='comment'>n</span><span class='comment'>e</span><span class='comment'>.</span><span class='comment'> </span><span class='comment'> </span><span class='comment'>A</span><span class='comment'>n</span><span class='comment'>o</span><span class='comment'>t</span><span class='comment'>h</span><span class='comment'>e</span><span class='comment'>r</span><span class='comment'> </span><span class='comment'>(</span><span class='comment'>p</span><span class='comment'>o</span><span class='comment'>s</span><span class='comment'>s</span><span class='comment'>i</span><span class='comment'>b</span><span class='comment'>l</span><span class='comment'>y</span><span class='comment'> </span><span class='comment'>m</span><span class='comment'>o</span><span class='comment'>r</span><span class='comment'>e</span><span class='comment'> </span><span class='comment'>r</span><span class='comment'>e</span><span class='comment'>a</span><span class='comment'>s</span><span class='comment'>o</span><span class='comment'>n</span><span class='comment'>a</span><span class='comment'>b</span><span class='comment'>l</span><span class='comment'>e</span><span class='comment'>)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='comment'>/</span><span class='comment'>/</span><span class='comment'> </span><span class='comment'>a</span><span class='comment'>l</span><span class='comment'>t</span><span class='comment'>e</span><span class='comment'>r</span><span class='comment'>n</span><span class='comment'>a</span><span class='comment'>t</span><span class='comment'>i</span><span class='comment'>v</span><span class='comment'>e</span><span class='comment'> </span><span class='comment'>i</span><span class='comment'>s</span><span class='comment'> </span><span class='comment'>t</span><span class='comment'>o</span><span class='comment'> </span><span class='comment'>j</span><span class='comment'>u</span><span class='comment'>m</span><span class='comment'>p</span><span class='comment'> </span><span class='comment'>b</span><span class='comment'>a</span><span class='comment'>c</span><span class='comment'>k</span><span class='comment'> </span><span class='comment'>t</span><span class='comment'>o</span><span class='comment'> </span><span class='comment'>t</span><span class='comment'>h</span><span class='comment'>e</span><span class='comment'> </span><span class='comment'>s</span><span class='comment'>t</span><span class='comment'>a</span><span class='comment'>r</span><span class='comment'>t</span><span class='comment'> </span><span class='comment'>o</span><span class='comment'>r</span><span class='comment'> </span><span class='comment'>s</span><span class='comment'>t</span><span class='comment'>r</span><span class='comment'>i</span><span class='comment'>n</span><span class='comment'>g</span><span class='comment'> </span><span class='comment'>s</span><span class='comment'>t</span><span class='comment'>a</span><span class='comment'>t</span><span class='comment'>e</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='comment'>/</span><span class='comment'>/</span><span class='comment'> </span><span class='comment'>a</span><span class='comment'>f</span><span class='comment'>t</span><span class='comment'>e</span><span class='comment'>r</span><span class='comment'> </span><span class='comment'>a</span><span class='comment'> </span><span class='comment'>c</span><span class='comment'>h</span><span class='comment'>a</span><span class='comment'>r</span><span class='comment'>a</span><span class='comment'>c</span><span class='comment'>t</span><span class='comment'>e</span><span class='comment'>r</span><span class='comment'> </span><span class='comment'>o</span><span class='comment'>r</span><span class='comment'> </span><span class='comment'>t</span><span class='comment'>w</span><span class='comment'>o</span><span class='comment'>.</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>break</span>;
&nbsp;&nbsp;&nbsp;&nbsp;}
&nbsp;&nbsp;&nbsp;&nbsp;<span class='statement'>return</span> oldstate;
}


</pre>
</body>
</html>
