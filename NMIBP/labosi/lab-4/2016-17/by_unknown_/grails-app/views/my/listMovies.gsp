<g:each in="${taskInstanceList}" var="p">
    <g:link action="showMovie" id="${p}"><li>${p}</li></g:link>
</g:each>