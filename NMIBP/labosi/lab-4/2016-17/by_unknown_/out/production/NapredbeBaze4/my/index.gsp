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
    <g:form action="list" method="GET">
        <div class="fieldcontain">
            <label for="query">Search for tasks:</label>
            <g:textField name="query" value="${params.query}"/>
        </div>
    </g:form>
</fieldset>
<table>


<g:radioGroup name="criteria" value="Filmovi" id="criteria"
              labels="['Filmovi','Glumci']"
              values="['Filmovi','Glumci']">

    <label>
        <span class="radioSpan">${it.radio}</span>
        ${it.label}
    </label>

</g:radioGroup>

<g:each in="${taskInstanceList}" var="p">
    <li>${p}</li>
</g:each>

<p>Ukupno trojki ${ukTrojkiInView}</p>



