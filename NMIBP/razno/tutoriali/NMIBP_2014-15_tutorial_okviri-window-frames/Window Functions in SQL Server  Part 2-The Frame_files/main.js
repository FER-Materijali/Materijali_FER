
require([
    "rss",
    "corner-peel",
    "ajax-comment-delete",
    "jquery.dlmenu",
    "audio-polyfill",
    "newsletter-subscriber",
    "analytics",
    "mobile-searchbar"
]);

require(["jquery"], function ($) {
    $(document).ready(function () {
        $(".show-on-ready").show();
    });

    var shareTools = $(".share-tools");
    if (shareTools.length) {
        shareTools.html(
            '<div class="addthis_toolbox addthis_default_style">' +
              '<p>Thank this author by sharing:</p>' +
              '<a class="addthis_button_google_plusone" g:plusone:annotation="none"></a>' +
              '<a class="addthis_button_linkedin"></a>' +
              '<a class="addthis_button_facebook"></a>' +
              '<a class="addthis_button_twitter"></a>' +
              '<a class="addthis_counter addthis_bubble_style"></a>' +
            '</div>'
        );
        addthis_config = {
            pubid: "ra-4f3bb4c87aeb8915"
        };

        loadScript("s7.addthis.com/js/250/addthis_widget.js");
    }

    function loadScript(src) {
        var scriptTag = document.createElement("script");
        scriptTag.type = "text/javascript";
        scriptTag.async = true;
        scriptTag.src = document.location.protocol + "//" + src;
        $("head").append(scriptTag);
    };

    $(".search-js input[type=text]").on("keydown", function (event) {
        if (event.keyCode === 13) {
            submitSearch($(this));
            return false;
        }
    });
    $(".search-js button").on("click", function () {
        submitSearch($(this));
        return false;
    });
    $(".search-js").show();

    function submitSearch(element) {
        var input = element.parents(".search-js").find("input[type=text]");
        var inputName = input.attr("name");
        var searchQuery = input.val();
        window.location = "/search?" + inputName + "=" + encodeURIComponent(searchQuery);
    }
});