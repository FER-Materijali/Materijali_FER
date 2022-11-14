<%@ page language="java" session="false" contentType="text/html; 
charset=UTF-8" %>
<%@page import="java.util.List" %>
<%@page import="hr.fer.zemris.java.tecaj_11.vjezba.BOperation" %>
<%@page import="hr.fer.zemris.java.tecaj_11.vjezba.BFunction" %>
<html>
<head>
<title>Booleove funkcije</title>
</head>
<body>
<table cols="2" border="0" align="left">
<tr><td><h2>Booleov kalkulator</h2></td></tr>
</table><br><br>
<%
List<BOperation> results = (List<BOperation>)request.getAttribute("operacije");
for( hr.fer.zemris.java.tecaj_11.vjezba.BOperation lista : results ) {
	String fja = lista.opDescription();
	out.print("<b>Izračun funkcije " + fja + "</b><br>");
	String crtanje = lista.toString();
	out.print(crtanje);
	out.print("<br>");
	out.print("<img src=\"bdraw?op=" + crtanje + "\" style=\"margin-top: 10px;\"><br>");	
	out.print("<br> <br>");
}
%>
</body>
</html>