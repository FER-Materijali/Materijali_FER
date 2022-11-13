require(["jquery", "mediaelement"], function ($) {
    var stylesheetIncluded = false;

    function includeStylesheet() {
        if (!stylesheetIncluded) {
            var url = "/static/js/lib/mediaelement/mediaelementplayer.css";
            // IE6 only allows stylesheets to be added through document.createStyleSheet
            if (document.createStyleSheet) {
                document.createStyleSheet(url);
            } else {
                $("head").append('<link rel="stylesheet" type="text/css" href="' + url + '">');   
            }
            stylesheetIncluded = true;
        }
    }

    $("audio").each(function () {
        if (requiresPolyfill(this)) {
            usePolyfill(this);
        }
    });

    function usePolyfill(audioElement) {
        includeStylesheet();
        $(audioElement).mediaelementplayer();
    }

    function requiresPolyfill(audioElement) {
        var sourceElements = $(audioElement).find("source");
        for (var i = 0; i < sourceElements.length; i++) {
            var sourceElement = sourceElements.get(i);
            var type = sourceElement.getAttribute("type");
            if (typeIsMp3(type) && canPlayMp3()) {
                return false;
            }
            if (typeIsVorbis(type) && canPlayVorbis()) {
                return false;
            }
        }
        return true;
    }

    // Somewhat fuzzy matching, but should be sufficient
    function typeIsMp3(type) {
        return /audio\/mpeg/.test(type);
    }

    function typeIsVorbis(type) {
        return /audio\/ogg/.test(type) && /vorbis/.test(type);
    }

    function canPlayMp3() {
        return canPlayType('audio/mpeg;');
    }

    function canPlayVorbis() {
        return canPlayType('audio/ogg; codecs="vorbis"');
    }

    function canPlayType(audioType) {
        var a = document.createElement('audio');
        return !!(a.canPlayType && a.canPlayType(audioType).replace(/no/, ''));
    }
});