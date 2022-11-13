<%--
  Created by IntelliJ IDEA.
  User: TheBestPCEver
  Date: 5.2.2017.
  Time: 20:10
--%>
<%@ page contentType="text/html;charset=UTF-8" %>
<g:if test="${flash.message}">
    <div class="message" role="status">${flash.message}</div>
</g:if>
<fieldset class="form">
    <g:form action="listMovies" method="GET">
        <div class="fieldcontain">
            <label for="query">Search for Movies:</label>
            <g:textField name="query" value="${params.query}"/>
        </div>
    </g:form>

    <fieldset class="form">
        <g:form action="listActors" method="GET">
            <div class="fieldcontain">
                <label for="query">Search for Actors:</label>
                <g:textField name="query" value="${params.query}"/>
            </div>
        </g:form>
    </fieldset>
</fieldset>



<p>Ukupno trojki ${ukTrojkiInView}</p>
<p>Ukupno filmova ${brFilmovaInVIew}</p>
<p>Ukupno akcijskih filmova ${brojAkcijskihInView}</p>
<p>Broj filmova u 2000. godini ${brojFilmovaOveGodineInView}</p>

<g:each in="${randFilmoviInView}" var="p">
    <g:link action="showMovie" id="${p}"><li>${p}</li></g:link>
</g:each>



