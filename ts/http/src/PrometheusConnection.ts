import axios, {AxiosInstance, AxiosRequestConfig} from 'axios';

export interface Metric {
  metric: string;
  __name__: string;
  instance: string;
  job: string;
}

export interface Record {
  metric: Metric;
  value: {number, string};
}

export class PrometheusConnection {
  private m_baseUrl: string;
  private m_timeout: number;
  private m_prometheusApi: AxiosInstance;

  public constructor(baseUrl: string) {
    this.m_baseUrl = baseUrl;
    this.m_timeout = 1000;

    let config: AxiosRequestConfig = {
      baseURL: baseUrl,
      method: 'get',
      timeout: this.m_timeout
    };

    this.m_prometheusApi = axios.create(config)
  }

  public async query(query: string, time?: number, timeout?: number):
      Promise<Record[]> {
    return new Promise<Record[]>((resolve, reject) => {
      this.m_prometheusApi.request(this.makeQuery(query, time, timeout))
        .then(response => {
            let records = new Array<Record>()
            for (let record of response.data.data['result']) {
              records.push(record)
            }
            resolve(records)
        })
        .catch(error => {
            reject(error)
        })
    })
  }

  private makeQuery(query: string, time?: number, timeout?: number):
      AxiosRequestConfig {
    const queryRequest:
        AxiosRequestConfig = {url: '/v1/query', params: {'query': query}};

    if (time) {
      queryRequest.params['time'] = time;
    }

    if (timeout) {
      queryRequest.params['timeout'] = timeout;
    }

    return queryRequest;
  }

}