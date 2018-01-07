import React, { Component } from 'react';
import { RingLoader } from 'react-spinners';
import Thermometer from 'react-thermometer-component'
import './App.css';

class App extends Component {

  state = {
    loading: true,
    person: {}
  }

  componentWillMount() {
    this.interval = setInterval(async () => {
      this.fetchPerson();
    }, 1000);
  }

  fetchPerson = async () => {
    const person = await (await fetch('http://192.168.0.105:8084/Radiator/api/person')).json();
    this.setState({ person, loading: false });
    console.log(person)
  }

  updateTemperature = async () => {
    const options = {
      headers: {
        'Accept': 'application/json',
        'Content-Type': 'application/json'
      },
      method: "PUT",
      body: JSON.stringify(this.state.person)
    }

    const res = await fetch('http://192.168.0.105:8084/Radiator/api/person', options);
  }

  render() {
    if (this.state.loading) {
      return (
        <div style={{ height: "100vh", display: "flex", background: "black" }}>
          <div className='currentTemperature'>
            <RingLoader
              color={'#36D7B7'}
              loading={this.state.loading}
            />
          </div>
        </div>
      )
    }

    return (
      <div style={{ background: "black", height: "100vh", display: "flex" }}>
        <div className="currentTemperature">
          <span style={{ float: "left", padding: 110 }}>
            {Math.floor(this.state.person.radiator.currentTemperature)}°C
          </span>
          <Thermometer
            theme="light"
            value={Math.floor(this.state.person.radiator.currentTemperature)}
            max="35"
            format="°C"
            size="large"
            height="300"
          />
        </div>
        <div style={{ clear: "left" }}>
          <span className="temperatureUp">
            <i class="material-icons md-96">keyboard_arrow_up</i>
          </span>
          <span>
            {this.state.person.radiator.temperature}
          </span>
          <span className="temperatureDown">
            <i class="material-icons md-96">keyboard_arrow_down</i>
          </span>
        </div>
      </div>
    );
  }
}

export default App;
