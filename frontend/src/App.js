import React, {Component} from 'react';
import {RingLoader} from 'react-spinners';
import Thermometer from 'react-thermometer-component'
import './App.css';

class App extends Component {

    state = {
        loading: true,
        person: {}
    }

    componentWillMount() {
        setInterval(async () => {
            this.fetchPerson();
        }, 10000);
    }

    fetchPerson = async () => {
        const person = await (await fetch('http://192.168.0.105:8084/Radiator/api/person')).json();
        this.setState({person, loading: false});
    }

    updateTemperature = async (e) => {
        let person = (this.state.person);
        if (e.target.id === 'up' && person.radiator.temperature < 30) {
            person.radiator.temperature++;
        } else if (e.target.id === 'down' && person.radiator.temperature > 10) {
            person.radiator.temperature--;
        }
        this.setState({person})
        const options = {
            headers: {
                'Accept': 'application/json',
                'Content-Type': 'application/json'
            },
            method: "PUT",
            body: JSON.stringify(person)
        }

        await fetch('http://192.168.0.105:8084/Radiator/api/person', options);
    }

    render() {
        if (this.state.loading) {
            return (
                <div style={{height: "100vh", background: "black"}}>
                    <div className='loadingScreen'>
                        <RingLoader
                            color={'#36D7B7'}
                            loading={this.state.loading}
                        />
                    </div>
                </div>
            )
        }

        return (
            <div className="container-fluid" style={{background: "black", height: "100vh"}}>
                <br/><br/><br/>
                <div className="row" style={{paddingTop: "30vh"}}>
                    <div className="col-4"/>
                    <div className="col-1">
                          <span className="temperatureUp unSelectable" onClick={this.updateTemperature}>
                            <i className="material-icons md-96" id="up">keyboard_arrow_up</i>
                        </span>
                        <span className="targetTemperature unSelectable">
                            {this.state.person.radiator.temperature}
                        </span>
                        <span className="temperatureDown unSelectable" onClick={this.updateTemperature}>
                            <i className="material-icons md-96" id="down">keyboard_arrow_down</i>
                        </span>
                    </div>
                    <div className="col-1">
                        <div style={{marginTop: "-90px", minWidth: 100}}>

                            <Thermometer
                                theme="light"
                                value={Math.floor(this.state.person.radiator.currentTemperature)}
                                max="35"
                                format="°C"
                                size="large"
                                height="300"
                            />
                        </div>
                    </div>
                    <div className="col-1">

                        <span className="currentTemperature unSelectable">
                                {Math.floor(this.state.person.radiator.currentTemperature)}°C
                        </span>

                    </div>
                    <div className="col"/>
                </div>


            </div>
        );
    }
}

export default App;
