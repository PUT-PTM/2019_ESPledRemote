<template>
<f7-app :params="f7params">
  <!-- Status bar overlay for fullscreen mode-->
  <f7-statusbar></f7-statusbar>

  <!-- Right panel with reveal effect-->
  <f7-panel right reveal theme-dark>
    <f7-view>
      <f7-page>
        <f7-block-title>Description</f7-block-title>
        <f7-block>Wireless lighting of the LED to the color specified by the user.</f7-block>
        <f7-block-title>Author</f7-block-title>
        <f7-block>
          <p>
            <i class="fas fa-copyright"></i>
            <span>Created by</span>
            <a target="_blank" class="link external git-link" href="https://github.com/SG-WebDev/">SG-WebDev</a>
          </p>
        </f7-block>
      </f7-page>
    </f7-view>
  </f7-panel>
  <!-- Your main view, should have "view-main" class -->
  <f7-view main class="safe-areas" url="/"></f7-view>
</f7-app>
</template>
<script>
  import cordovaApp from '../js/cordova-app.js';
  import routes from '../js/routes.js';

  export default {
    data() {
      return {
        // Framework7 Parameters
        f7params: {
          id: 'io.espled.app', // App bundle ID
          name: 'ESPledRemote', // App name
          theme: 'md', // Automatic theme detection
          panels3d: {
            enabled: true,
          },
          // App routes
          routes: routes,
          // Input settings
          input: {
            scrollIntoViewOnFocus: !!this.$device.cordova,
            scrollIntoViewCentered: !!this.$device.cordova,
          },
          // Cordova Statusbar settings
          statusbar: {
            overlay: this.$device.cordova && this.$device.ios || 'auto',
            iosOverlaysWebView: true,
            androidOverlaysWebView: false,
          },
        },
      }
    },
    methods: {
    },
    mounted() {
      this.$f7ready((f7) => {
        // Init cordova APIs (see cordova-app.js)
        if (f7.device.cordova) {
          cordovaApp.init(f7);
        }
        // Call F7 APIs here
      });
    }
  }
</script>