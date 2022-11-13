var _gaq = _gaq || [];

require(["jquery"], function ($) {
    _gaq.push(['_setAccount', 'UA-90206-4']);
    _gaq.push(['_setDomainName', 'simple-talk.com']);
    _gaq.push(['_setAllowLinker', true]);

    // all RG sites
    var RGsites = new Array("red-gate.com", "sqlservercentral.com", "simple-talk.com");

    var i;
    // remove current domain 
    for (i = 0; i < RGsites.length; i++) {
        if (document.domain.indexOf(RGsites[i]) != -1) {
            RGsites.splice(i, 1);
            break;
        }
    }

    // set the customVar if not a self-referrer
    if (document.referrer.indexOf("http://" + document.domain) == -1) {
        for (i = 0; i < RGsites.length; i++) {
            if (document.referrer.indexOf(RGsites[i]) != -1) {
                _gaq.push(["_setCustomVar", 2, "RG referral", document.referrer, 1]);
                break;
            }
        }
    }


    _gaq.push(['_trackPageview']);

    var intDoms = '(red-gate.com|simple-talk.com|sqlservercentral.com)';
    var baseDom = location.hostname.match(RegExp(intDoms + '$'));
    baseDom = (baseDom ? baseDom[1].replace(/\:\d+/, '') : location.hostname);

    // gaAddons FREE v1.0, Copyright 2011, Stephane Hamel - http://gaAddons.com
    // Licensed under a Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported License
    // gaAddons FREE v1.0, Copyright 2011, Stephane Hamel - http://gaAddons.com
    // gaAddons by Stephane Hamel is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.
    // Refactored by Simon Rouger.
    // This code is provided as is, without guarantee or support.

    ///////////////////
    // _trackDownloads
    $(document).ready(function () {
        // helper function - allow regex as jQuery selector
        $.extend(
            $.expr[':'].regex = function (e, l, m) {
                var mP = m[3].split(','),
                    l = /^(data|css):/,
                    a = {
                        method: mP[0].match(l) ? mP[0].split(':')[0] : 'attr',
                        property: mP.shift().replace(l, '')
                    },
                    r = new RegExp(mP.join('').replace(/^\s+|\s+$/g, ''), 'ig');
                return r.test($(e)[a.method](a.property));
            }
        );

        $('a:regex(href,\\.(zip|mp\\d+|mpe*g|pdf|docx*|pptx*|xlsx*|jpe*g|png|gif|tiff*|exe)$)').on('click', function (e) {
            _gaq.push(['_trackEvent', 'DownloadFile', 'Click', this.href.replace(/^.*\/\//, '')]);
        });
    });

    ///////////////////
    // _trackMailTo
    $(document).ready(function () {
        $('a[href^="mailto"]').on('click', function (e) {
            _gaq.push(['_trackEvent', 'Email', 'Click', this.href.replace(/^mailto:/i, '')]);
        });
    });

    ///////////////////
    // _trackOutbound
    $(document).ready(function () {
        $('a[href^="http"]:not([href*="//' + location.host + '"])').on('click', function (e) {

            var intTxt = '';
            var outLink = '/outbound/';
            var intSite = this.href.match(intDoms);

            if (intSite) {
                // insert extra txt for RG site
                if (intSite[1] != baseDom) {
                    intTxt = 'RG/';
                }
            }

            outLink = outLink + intTxt + this.href.match(/\/\/([^\/]+)/)[1];

            _gaq.push(['_trackPageview', outLink]);

            if (intTxt == 'RG/') {
                _gaq.push(['_link', this.href]);
                return false;
            }

        });
    });

    (function () {
        var ga = document.createElement('script');
        ga.type = 'text/javascript';
        ga.async = true;
        ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
        var s = document.getElementsByTagName('script')[0];
        s.parentNode.insertBefore(ga, s);
    })();
});