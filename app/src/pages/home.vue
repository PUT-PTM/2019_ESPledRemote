<template>
  <f7-page name="home">
    <!-- Top Navbar -->
    <f7-navbar title="ESPledRemote">
      <f7-nav-right>
        <f7-link panel-open="right"><i class="fas fa-info-circle"></i></f7-link>
      </f7-nav-right>
    </f7-navbar>
    <!-- Page content-->
    <f7-block>
      <f7-row>
        <f7-col>
          <ColorPicker :width="300" :height="300" :disabled="false" startColor="#ffffff" @colorChange="onColorChange"></ColorPicker>
        </f7-col>
      </f7-row>
      <f7-row>
        <f7-col class="selected-color">
          <svg height="50" width="50">
            <circle cx="25" cy="25" r="25" :fill="hexColor" />
          </svg>
        </f7-col>
      </f7-row>
      <f7-row>
        <f7-col>
          <f7-button fill large @click="turnOn">Turn On</f7-button>
        </f7-col>
        <f7-col>
          <f7-button outline large @click="turnOff">Turn off</f7-button>
        </f7-col>
      </f7-row>
    </f7-block>

  </f7-page>
</template>
<style>
  #color-wheel {
    margin: 10px auto;
  }
  .selected-color {
    display: flex;
    justify-content: center;
    align-items: center;
    margin: 15px auto;
  }
</style>
<script>
  import ColorPicker from 'vue-color-picker-wheel';
  import axios from 'axios';

  export default {
    name: 'app',
    data() {
      return {
        hexColor: null,
        rColor: null,
        gColor: null,
        bColor: null,
        active: false,
      }
    },
    components: {
      ColorPicker
    },
    methods: {
      onColorChange(color) {
        this.hexColor = color;
        console.log('HEXColor has changed to: ', this.hexColor);
        color = color.replace('#', '');
        this.rColor = parseInt(color.substring(0, 2), 16);
        this.gColor = parseInt(color.substring(2, 4), 16);
        this.bColor = parseInt(color.substring(4, 6), 16)
        console.log(`R: ${this.rColor},G: ${this.gColor},B: ${this.bColor}`);
      },
      turnOn() {
        this.active = true;
        axios.get(`http://192.168.43.233/${this.active}/${this.rColor}/${this.gColor}/${this.bColor}`)
                .then(response => {
                  console.log(response.data);
                  this.$f7.dialog.alert(`LED is lighted!`);
                })
                .catch(e => {
                  this.errors.push(e)
                })
      },
      turnOff() {
        this.active = false;
        axios.get(`http://192.168.43.233/${this.active}`)
                .then(response => {
                  console.log(response.data);
                  this.$f7.dialog.alert(`Darkness is came!`);
                })
                .catch(e => {
                  this.errors.push(e)
                })
      }
    },
  };
</script>