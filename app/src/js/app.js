// Import Vue
import Vue from 'vue';

// Import Framework7
import Framework7 from 'framework7/framework7.esm.bundle.js';

// Import Framework7-Vue Plugin
import Framework7Vue from 'framework7-vue/framework7-vue.esm.bundle.js';
import Framework73dPanels from 'framework7-plugin-3d-panels/dist/framework7.3dpanels.min.js';

// Import Framework7 Styles
import 'framework7/css/framework7.bundle.css';
import 'framework7-plugin-3d-panels/dist/framework7.3dpanels.css';

// Import Icons and App Custom Styles

import '../css/app.scss';

// Import App Component
import App from '../components/app.vue';

// Init Framework7-Vue Plugin
Framework7.use(Framework7Vue);
Framework7.use(Framework73dPanels);

// Init App
new Vue({
  el: '#app',
  render: (h) => h(App),

  // Register App Component
  components: {
    app: App
  },
});