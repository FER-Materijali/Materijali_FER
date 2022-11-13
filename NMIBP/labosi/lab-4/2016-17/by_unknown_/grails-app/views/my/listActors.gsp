<g:each in="${taskInstanceList}" var="p">
    <g:link action="showActor" id="${p}"><li>${p}</li></g:link>
</g:each>