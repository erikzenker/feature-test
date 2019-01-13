import {expect} from 'chai';

import {PrometheusConnection} from '../src/PrometheusConnection';

describe('PrometheusConnection', () => {
  it('should construct', () => {
    let request = new PrometheusConnection('http://localhost:9090/api');
  });

  it('should query for up time', function(done) {
    let request = new PrometheusConnection('http://localhost:9090/api');
    request.query('up').then((response) => {
        expect(response[0].metric.__name__).to.be.equal("up")
        expect(response[0].metric.instance).to.be.equal("localhost:9090")
        expect(response[0].metric.job).to.be.equal("prometheus")
        expect(response[0].value[1]).to.be.equal("1")
        expect(response[0].value[0]).to.be.greaterThan(0)
        done()
    }).catch((error) => {
        done(error)    
    });
  });

});
